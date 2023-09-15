#include "unity.h"
#include "list.h"
#include "plugin.h"
#include "error.h"

#include "slog.h"
#include <stdbool.h>
#include <string.h>


static inline bool list_empty(list_t *list)
{
	return (list->next == list);
}

static inline bool entry_linked(list_entry_t *entry)
{
	return entry->next != entry;
}

/* An entry is initialized when it points to itself */
static inline void list_init_entry(list_entry_t *entry)
{
	entry->next = entry;
	entry->prev = entry;
}

/* An initialized list is just an initialized entry */
static inline void list_init(list_t *list)
{
	list_init_entry(list);
}

/* Link an entry between two other entries in the list */
static inline void list_link_entry(list_entry_t *entry, list_entry_t *prev,
		list_entry_t *next)
{
	entry->next = next;
	next->prev = entry;
	entry->prev = prev;
	prev->next = entry;
}

/* Unlink an entry from the list */
static inline void list_unlink_entry(list_entry_t *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
	list_init_entry(entry);
}

/* Adding an entry in the head of a list is equivalent to linking it
 * between the head of the list and its next */
static inline void list_add_head(list_t *list, list_entry_t *entry)
{
	list_link_entry(entry, list, list->next);
}

/* Adding an entry in the tail of a list is equivalent to linking it
 * between the head of the list and its prev */
static inline void list_add_tail(list_t *list, list_entry_t *entry)
{
	list_link_entry(entry, list->prev, list);
}

static inline list_entry_t *list_remove_head(list_t *list)
{
	if (list_empty(list))
		return NULL;

	list_entry_t *ret = list->next;
	list_unlink_entry(ret);

	return ret;
}

static inline list_entry_t *list_remove_tail(list_t *list)
{
	if (list_empty(list))
		return NULL;

	list_entry_t *ret = list->prev;
	list_unlink_entry(ret);

	return ret;
}

/* Get the container of an entry
 *
 * This is a helper macro that allows us to get a pointer to
 * the struct that contains a list entry
 *
 * \param[in] ptr A pointer to the entry
 * \param[in] type The type of the container
 * \param[in] name The name of the container entry field
 *
 * \returns A pointer to the container including the entry
 *
 */
#define get_container(ptr, type, name) \
	(type *)((char *)ptr - offsetof(type, name))

/* Iterate through all the entries of a list
 *
 * \param[out] iter An iterator to use for keeping the pointer to
 *             the current list entry of each iteration
 * \param[in] list The list head of the list to iterate
 */
#define for_each(iter, list) \
	for (iter = (list)->next; iter != (list); iter = iter->next)

/* Iterate through all the containers of a list
 *
 * \param[out] iter An iterator to use for keeping the pointer to
 *             the current list entry container for each iteration
 * \param[in] list The head of the list to iterate
 * \param[in] member The name of list_entry_t field of the container
 */
#define for_each_container(iter, list, type, member) \
	for (iter = get_container((list)->next, type, member); \
		&iter->member != (list); \
	       iter = get_container(iter->member.next, type, member))

/* Iterate through all the containers of a list safely
 *
 * This flavour of the iterator allows you to modify the container you
 * are accessing in each iteration, e.g. remove it from the list.
 *
 * \param[out] iter An iterator to use for keeping the pointer to
 *             the current list entry container for each iteration
 * \param[out] tmp_iter An iterator to use temporarily for safely
 *             traversing the list
 * \param[in] list The head of the list to iterate
 * \param[in] member The name of list_entry_t field of the container
 */
#define for_each_container_safe(iter, tmp_iter, list, type, member) \
	for (iter = get_container((list)->next, type, member), \
		tmp_iter = get_container(iter->member.next, type, member); \
		&iter->member != (list); \
		iter = tmp_iter, \
		tmp_iter = get_container(tmp_iter->member.next, type, member))



static const char *pname = "mock_plugin";
static struct vaccel_plugin plugin = {0};
static struct vaccel_plugin_info pinfo = {0};

static int fini(void) 
{
    return VACCEL_OK;
}

static int init(void) 
{
    return VACCEL_OK;
}

// Function to set up your test environment
void setUp(void) 
{
    plugin.info = &pinfo;
    pinfo.name = pname;
    list_init_entry(&plugin.entry);
    list_init_entry(&plugin.ops);
    pinfo.init = init;
    pinfo.fini = fini;

    plugins_bootstrap();
}


// Function to tear down your test environment
void tearDown(void) 
{
    plugins_shutdown();
}

void test_plugin_null(void) 
{
    TEST_ASSERT_EQUAL(register_plugin(NULL), VACCEL_EINVAL);
}

void test_plugin_null_name(void)
{
    struct vaccel_plugin_info info = { 0 };
	struct vaccel_plugin plugin;
	plugin.info = &pinfo;
	
    plugin.entry.next = &(plugin.entry);
    plugin.entry.prev = &(plugin.entry);

    TEST_ASSERT_EQUAL(register_plugin(&plugin), VACCEL_EINVAL);
}

void test_plugin_not_boostrapped(void)
{
    struct vaccel_plugin plugin = {};
    
    TEST_ASSERT_NOT_EQUAL(register_plugin(&plugin), VACCEL_EBACKEND);
}

void test_plugin_init_values_all(void)
{
    TEST_ASSERT_EQUAL(register_plugin(&plugin), VACCEL_OK);
    TEST_ASSERT_EQUAL(strcmp(plugin.info->name, "mock_plugin"), 0);
    TEST_ASSERT_TRUE(list_empty(&plugin.ops));

}

void test_plugin_exists(void)
{
    TEST_ASSERT_EQUAL(register_plugin(&plugin), VACCEL_OK);
    TEST_ASSERT_EQUAL(register_plugin(&plugin), VACCEL_EEXISTS);
}

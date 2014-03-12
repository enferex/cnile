#include <gcc-plugin.h>
#include <opts.h>
#include <toplev.h>

int plugin_is_GPL_compatible = 666;

static void retreet(void *gcc_data, void *user_data)
{
    unsigned i;

    for (i=0; i<save_decoded_options_count; ++i)
      printf("[%d] Option: %s\n",
             i, save_decoded_options[i].orig_option_with_args_text);
}

int plugin_init(
    struct plugin_name_args *plugin_info,
    struct plugin_gcc_version *version)
{

    register_callback(plugin_info->base_name, PLUGIN_ALL_IPA_PASSES_END, retreet, NULL);
    return 0;
}

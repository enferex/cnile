/* retreet: GCC plugin to store the build command arguments in the binary
 *
 * Copyright (C) 2014  Matt Davis (enferex)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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

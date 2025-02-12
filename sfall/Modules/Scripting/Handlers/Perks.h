/*
 *    sfall
 *    Copyright (C) 2008-2023  The sfall team
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace sfall
{
namespace script
{

void __declspec() op_get_perk_owed();

void __declspec() op_set_perk_owed();

void __declspec() op_set_perk_freq();

void op_get_perk_available(OpcodeContext&);

void op_set_perk_name(OpcodeContext&);

void op_set_perk_desc(OpcodeContext&);

void __declspec() op_set_perk_value();

void op_set_selectable_perk(OpcodeContext&);

void op_set_fake_perk(OpcodeContext&);

void op_set_fake_trait(OpcodeContext&);

void mf_set_selectable_perk_npc(OpcodeContext&);

void mf_set_fake_perk_npc(OpcodeContext&);

void mf_set_fake_trait_npc(OpcodeContext&);

void __declspec() op_set_perkbox_title();

void __declspec() op_hide_real_perks();

void __declspec() op_show_real_perks();

void __declspec() op_clear_selectable_perks();

void op_has_fake_perk(OpcodeContext&);

void op_has_fake_trait(OpcodeContext&);

void mf_has_fake_perk_npc(OpcodeContext&);

void mf_has_fake_trait_npc(OpcodeContext&);

void __declspec() op_perk_add_mode();

void __declspec() op_remove_trait();

void __declspec() op_set_pyromaniac_mod();

void __declspec() op_apply_heaveho_fix();

void __declspec() op_set_swiftlearner_mod();

void __declspec() op_set_perk_level_mod();

void mf_add_trait(OpcodeContext&);

}
}

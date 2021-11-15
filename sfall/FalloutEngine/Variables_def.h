// List of all engine variables and their types.
// Used to generate fo::var::var_name constants.

// TODO: assign appropriate types (arrays, structs, strings, etc.) for all variables

VAR_(aiInfoList,                 DWORD)
VAR_(ambient_light,              DWORD)
VARA(anim_set,                   fo::AnimationSet, 32)
VARA(art,                        fo::Art, 11)
VAR_(art_name,                   DWORD)
VAR_(art_vault_guy_num,          DWORD)
VAR_(art_vault_person_nums,      DWORD)
VARA(backgrndRects,              fo::BoundRect, 8)
VAR_(background_volume,          DWORD)
VAR_(bckgnd,                     BYTE*)
VAR_(black_palette,              DWORD)
VAR_(BlueColor,                  BYTE)
VAR_(bottom_line,                DWORD)
VAR_(btable,                     DWORD)
VAR_(btncnt,                     DWORD)
VARD(cap,                        fo::AIcap) // dynamic array
VAR_(carCurrentArea,             DWORD)
VAR_(carGasAmount,               long) // from 0 to 80000
VAR_(cmap,                       DWORD)
VAR_(colorTable,                 DWORD)
VAR_(combat_end_due_to_load,     DWORD)
VAR_(combat_free_move,           DWORD)
VARD(combat_list,                fo::GameObject*)
VAR_(combat_obj,                 fo::GameObject*)
VAR_(combat_state,               DWORD)
VAR_(combat_turn_obj,            fo::GameObject*)
VAR_(combat_turn_running,        DWORD)
VAR_(combatNumTurns,             DWORD)
VAR3(crit_succ_eff,              fo::CritInfo, 20, 9, 6)  // 20 critters with 9 body parts and 6 effects each
VAR_(critter_db_handle,          fo::PathNode*)
VAR_(critterClearObj,            DWORD)
VAR_(crnt_func,                  DWORD)
VAR_(cur_id,                     DWORD)
VAR_(curr_anim_set,              DWORD)
VAR_(curr_anim_counter,          DWORD)
VAR_(curr_font_num,              DWORD)
VARA(curr_pc_stat,               long, fo::PCSTAT_max_pc_stat)
VAR_(curr_stack,                 DWORD)
VAR_(currentProgram,             fo::Program*)
VAR_(cursor_line,                DWORD)
VAR_(DARK_GREY_Color,            BYTE)
VAR_(DarkGreenColor,             BYTE)
VAR_(DarkGreenGreyColor,         BYTE)
VAR_(dialog_target,              fo::GameObject*)
VAR_(dialog_target_is_party,     DWORD)
VAR_(dialogue_state,             DWORD)
VAR_(dialogue_switch_mode,       DWORD)
VARC(dialogueBackWindow,         DWORD)
VAR_(disp_rect,                  fo::BoundRect)
VAR_(dropped_explosive,          DWORD)
VARA(drugInfoList,               fo::DrugInfoList, 9)
VAR_(DullPinkColor,              BYTE)
VARC(edit_win,                   DWORD)
VAR_(editor_message_file,        fo::MessageList)
VAR_(Educated,                   DWORD)
VAR_(elevation,                  DWORD)
VAR_(endgame_subtitle_done,      DWORD)
VAR_(endWindowRect,              fo::BoundRect)
VAR_(Experience_pc,              DWORD)
VAR_(fallout_game_time,          DWORD)
VAR_(fidgetFID,                  DWORD)
VAR_(flptr,                      DWORD)
VAR_(folder_card_desc,           DWORD)
VAR_(folder_card_fid,            DWORD)
VAR_(folder_card_title,          DWORD)
VAR_(folder_card_title2,         DWORD)
VAR_(frame_time,                 DWORD)
VAR_(free_perk,                  char)
VARD(game_global_vars,           long)  // dynamic array of size == num_game_global_vars
VAR_(game_user_wants_to_quit,    DWORD)
VAR_(gcsd,                       fo::CombatGcsd*)
VAR_(gdBarterMod,                DWORD)
VAR_(gdNumOptions,               DWORD)
VAR_(gIsSteal,                   DWORD)
VAR_(glblmode,                   DWORD)
VAR_(gmouse_3d_current_mode,     long)
VAR_(gmouse_current_cursor,      long)
VARA(gmovie_played_list,         BYTE, 17)
VAR_(GoodColor,                  BYTE)
VAR_(GreenColor,                 BYTE)
VAR_(gsound_initialized,         DWORD)
VARA(hit_location_penalty,       long, 9)
VAR_(holo_flag,                  DWORD)
VAR_(holopages,                  DWORD)
VAR_(hot_line_count,             DWORD)
VAR_(i_fid,                      DWORD)
VAR_(i_lhand,                    fo::GameObject*)
VAR_(i_rhand,                    fo::GameObject*)
VARC(i_wid,                      DWORD)
VAR_(i_worn,                     fo::GameObject*)
VAR_(idle_func,                  void*)
VAR_(In_WorldMap,                DWORD) // moving on WorldMap
VAR_(info_line,                  DWORD)
VARC(interfaceWindow,            DWORD)
VAR_(intfaceEnabled,             DWORD)
VAR_(intotal,                    DWORD)
VAR_(inven_dude,                 fo::GameObject*)
VAR_(inven_pid,                  DWORD)
VAR_(inven_scroll_dn_bid,        DWORD)
VAR_(inven_scroll_up_bid,        DWORD)
VAR_(inventry_message_file,      fo::MessageList)
VARA(iscr_data,                  fo::InventScrData, 6)
VARA(itemButtonItems,            fo::ItemButtonItem, 2) // 0 - left, 1 - right
VAR_(itemButtonRect,             fo::BoundRect)
VAR_(itemCurrentItem,            long)  // 0 - left, 1 - right
VAR_(kb_lock_flags,              DWORD)
VARA(language,                   char, 32)
VAR_(last_buttons,               DWORD)
VAR_(last_button_winID,          DWORD)
VAR_(last_level,                 DWORD)
VAR_(Level_pc,                   DWORD)
VAR_(Lifegiver,                  DWORD)
VAR_(LIGHT_GREY_Color,           BYTE)
VAR_(lipsFID,                    DWORD)
VAR_(list_com,                   DWORD)
VAR_(list_total,                 DWORD)
VAR_(loadingGame,                DWORD)
VAR_(LSData,                     DWORD)
VAR_(lsgwin,                     DWORD)
VAR_(main_ctd,                   fo::ComputeAttackResult)
VAR_(main_death_voiceover_done,  DWORD)
VAR_(main_window,                DWORD)
VAR_(map_elevation,              DWORD)
VAR_(map_global_vars,            long*)  // array
VAR_(map_number,                 DWORD)
VAR_(master_db_handle,           fo::PathNode*)
VAR_(master_volume,              DWORD)
VAR_(max,                        DWORD)
VAR_(maxScriptNum,               long)
VAR_(Meet_Frank_Horrigan,        bool)
VAR_(mouse_buttons,              DWORD)
VAR_(mouse_hotx,                 DWORD)
VAR_(mouse_hoty,                 DWORD)
VAR_(mouse_is_hidden,            DWORD)
VAR_(mouse_x_,                   DWORD)
VAR_(mouse_y,                    DWORD)
VAR_(mouse_y_,                   DWORD)
VAR_(movePointRect,              fo::BoundRect)
VARA(movie_list,                 const char*, 17)
VAR_(Mutate_,                    DWORD)
VAR_(name_color,                 DWORD)
VAR_(name_font,                  DWORD)
VAR_(name_sort_list,             DWORD)
VAR_(num_caps,                   DWORD)
VAR_(num_game_global_vars,       DWORD)
VAR_(num_map_global_vars,        DWORD)
VAR_(num_windows,                DWORD)
VAR_(obj_dude,                   fo::GameObject*)
VARA(objectTable,                fo::ObjectTable*, 40000)
VAR_(objItemOutlineState,        DWORD)
VAR_(optionRect,                 DWORD)
VAR_(optionsButtonDown,          DWORD)
VAR_(optionsButtonDown1,         DWORD)
VAR_(optionsButtonDownKey,       DWORD)
VAR_(optionsButtonUp,            DWORD)
VAR_(optionsButtonUp1,           DWORD)
VAR_(optionsButtonUpKey,         DWORD)
VARC(optnwin,                    DWORD)
VAR_(outlined_object,            fo::GameObject*)
VAR_(partyMemberAIOptions,       DWORD)
VAR_(partyMemberCount,           DWORD)
VAR_(partyMemberLevelUpInfoList, DWORD*)
VAR_(partyMemberList,            fo::ObjectListData*) // dynamic array
VAR_(partyMemberMaxCount,        DWORD)
VARD(partyMemberPidList,         DWORD) // dynamic array
VAR_(patches,                    char*)
VAR_(paths,                      fo::PathNode*)  // array
VAR2(pc_crit_succ_eff,           fo::CritInfo, 9, 6)  // 9 body parts, 6 effects
VAR_(pc_kill_counts,             DWORD)
VARA(pc_name,                    char, 32)
VAR_(pc_proto,                   fo::Proto)
VARA(pc_trait,                   long, 2)  // 2 of them
VAR_(PeanutButter,               BYTE)
VARA(perk_data,                  fo::PerkInfo, fo::PERK_count)
VARD(perkLevelDataList,          fo::PartyMemberPerkListData) // dynamic array, limited to (PERK_Count * partyMemberMaxCount)
VARC(pip_win,                    DWORD)
VAR_(pipboy_message_file,        fo::MessageList)
VAR_(pipmesg,                    DWORD)
VAR_(preload_list_index,         DWORD)
VARA(procTableStrs,              const char*, (int)fo::Scripts::ScriptProc::count)  // table of procId (from define.h) => procName map
VAR_(proto_main_msg_file,        fo::MessageList)
VARA(proto_msg_files,            fo::MessageList, 6)  // array of 6 elements
VARA(protoLists,                 fo::ProtoList, 11)
VAR_(ptable,                     DWORD)
VAR_(pud,                        DWORD)
VAR_(queue,                      fo::Queue*)
VAR_(quick_done,                 DWORD)
VAR_(read_callback,              DWORD)
VAR_(rectList,                   fo::RectList*)
VAR_(RedColor,                   BYTE)
VAR2(retvals,                    fo::ElevatorExit, 24, 4)  // 24 elevators, 4 exits each
VAR_(rotation,                   DWORD)
VAR_(sampleRate,                 DWORD)
VAR_(script_path_base,           const char*)
VAR_(scr_size,                   fo::BoundRect)
VAR_(scriptListInfo,             fo::ScriptListInfoItem*)  // dynamic array
VARA(skill_data,                 fo::SkillInfo, fo::SKILL_count)
VARC(skldxwin,                   DWORD)
VAR_(slot_cursor,                DWORD)
VAR_(sndfx_volume,               DWORD)
VAR_(sneak_working,              DWORD) // DWORD var
VAR_(sound_music_path1,          char*)
VAR_(sound_music_path2,          char*)
VAR_(speech_volume,              DWORD)
VAR_(square,                     DWORD)
VAR_(square_rect,                fo::SquareRect) // _square_y
VAR_(squares,                    DWORD*)
VARA(stack,                      DWORD, 10)
VARA(stack_offset,               DWORD, 10)
VARA(stat_data,                  fo::StatInfo, fo::STAT_real_max_stat)
VAR_(stat_flag,                  DWORD)
VAR_(subtitleList,               fo::SubTitleList*)
VARA(sWindows,                   fo::sWindow, 16)
VAR_(Tag_,                       DWORD)
VAR_(tag_skill,                  DWORD)
VAR_(target_curr_stack,          DWORD)
VAR_(target_pud,                 DWORD*)
VARA(target_stack,               DWORD, 10)
VARA(target_stack_offset,        DWORD, 10)
VAR_(target_str,                 DWORD)
VAR_(target_xpos,                DWORD)
VAR_(target_ypos,                DWORD)
VAR_(text_char_width,            DWORD)
VAR_(text_height,                DWORD)
VAR_(text_max,                   DWORD)
VAR_(text_mono_width,            DWORD)
VAR_(text_object_index,          DWORD)
VARA(text_object_list,           fo::FloatText*, 20)
VAR_(text_spacing,               DWORD)
VAR_(text_to_buf,                DWORD)
VAR_(text_width,                 DWORD)
VAR_(tile,                       DWORD)
VAR_(title_color,                DWORD)
VAR_(title_font,                 DWORD)
VARA(trait_data,                 fo::TraitInfo, fo::TRAIT_count)
VAR_(use_language,               DWORD)
VAR_(view_page,                  DWORD)
VAR_(wd_obj,                     DWORD)
VARA(window,                     fo::Window*, 50)
VARA(window_index,               DWORD, 50)
VAR_(WhiteColor,                 BYTE)
VAR_(wmAreaInfoList,             DWORD)
VARC(wmBkWin,                    DWORD)
VAR_(wmBkWinBuf,                 BYTE*)
VAR_(wmLastRndTime,              DWORD)
VAR_(wmMaxTileNum,               DWORD)
VAR_(wmMsgFile,                  fo::MessageList)
VAR_(wmNumHorizontalTiles,       DWORD)
VAR_(wmViewportRightScrlLimit,   DWORD)
VAR_(wmViewportBottomtScrlLimit, DWORD)
VAR_(wmWorldOffsetX,             long)
VAR_(wmWorldOffsetY,             long)
VAR_(world_xpos,                 DWORD)
VAR_(world_ypos,                 DWORD)
VAR_(WorldMapCurrArea,           DWORD)
VAR_(YellowColor,                BYTE)

#undef VAR_
#undef VARC
#undef VARP
#undef VARA
#undef VAR2
#undef VAR3
#undef VARD

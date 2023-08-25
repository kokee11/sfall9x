#ifndef LIB_MISC_H
#define LIB_MISC_H

/**
  Some generic procedures
*/
/*
procedure round(variable val) begin
   variable intp;
   intp := floor(val);
   if ((val-intp) >= 0.5) then intp++;
   return intp;
end*/

// this fixes strange behavior when using negative float values
// looks like the only way to create correct negative float is to use atof()
// DEPRECATED as of sfall 3.4 (engine bug fixed)
/*procedure itof_safe(variable var) begin
   if (var < 0) then begin
      var := atof("-"+(-var));
   end
   return var;
end*/

// Parse keyboard shortcut definition
procedure parse_hotkey(variable string) begin
   variable lst;
   variable n;
   lst := string_split(string, "+");
   if (len_array(lst) == 0) then
      return 0;
   n := atoi(lst[0]);
   if (len_array(lst) > 1) then
      n += atoi(lst[1])*0x10000;
   return n;
end

// Check if shortcut is pressed
procedure hotkey_pressed(variable n) begin
   if (n < 0x10000) then
      return key_pressed(n);
   else
      return key_pressed(n bwand 0xFFFF) and key_pressed((n bwand 0xFFFF0000) / 0x10000);
end

// same as above, but suited for hs_keypress hook when keycode is already known
procedure hotkey_pressed_now(variable n, variable key) begin
   if (n < 0x10000) then
      return key == n;
   else begin
      variable k1 := (n bwand 0xFFFF),
               k2 := ((n bwand 0xFFFF0000) / 0x10000);
      if (k1 == key) then begin
         if (key_pressed(k2)) then return true;
      end else if (k2 == key) then begin
         if (key_pressed(k1)) then return true;
      end
      return false;
   end
end

// Loads ini section as map of keys and values parsed as integers (0 values will be skipped!)
procedure get_ini_section_int_to_int(variable file, variable section, variable fixArray := false) begin
   variable ar, ar2 := temp_array_map, k, v;
   ar := get_ini_section(file, section);
   foreach k: v in ar begin
      ar2[atoi(k)] := atoi(v);
   end
   if (fixArray) then
      fix_array(ar2);
   return ar2;
end


#endif

// Initialise the global array that allows the lookup of the depth of a given object
// GM2.0 does not have a depth on objects so on import from 1.x a global array is created
// NOTE: MacroExpansion is used to insert the array initialisation at import time
gml_pragma( "global", "__global_object_depths()");

// insert the generated arrays here
global.__objectDepths[0] = 0; // object_cha_tank
global.__objectDepths[1] = 0; // object_cha_attack
global.__objectDepths[2] = 0; // object_cha_heal
global.__objectDepths[3] = 0; // me_ob
global.__objectDepths[4] = 0; // object_en_big
global.__objectDepths[5] = 0; // object_en_mini
global.__objectDepths[6] = 0; // object_en_gun
global.__objectDepths[7] = 0; // object_en_fight
global.__objectDepths[8] = 0; // object_en_bu_
global.__objectDepths[9] = 0; // object_bu_all
global.__objectDepths[10] = 0; // object_en_big_hp
global.__objectDepths[11] = -20; // object_hp
global.__objectDepths[12] = -19; // object_bu_bar
global.__objectDepths[13] = 0; // wall_ob
global.__objectDepths[14] = 0; // obj_coin
global.__objectDepths[15] = 0; // object_start
global.__objectDepths[16] = 0; // object_load
global.__objectDepths[17] = 0; // object_bu_u
global.__objectDepths[18] = 0; // object_bu_r
global.__objectDepths[19] = 0; // object_bu_d
global.__objectDepths[20] = 0; // object_bu_l
global.__objectDepths[21] = 0; // object_drag_drop


global.__objectNames[0] = "object_cha_tank";
global.__objectNames[1] = "object_cha_attack";
global.__objectNames[2] = "object_cha_heal";
global.__objectNames[3] = "me_ob";
global.__objectNames[4] = "object_en_big";
global.__objectNames[5] = "object_en_mini";
global.__objectNames[6] = "object_en_gun";
global.__objectNames[7] = "object_en_fight";
global.__objectNames[8] = "object_en_bu_";
global.__objectNames[9] = "object_bu_all";
global.__objectNames[10] = "object_en_big_hp";
global.__objectNames[11] = "object_hp";
global.__objectNames[12] = "object_bu_bar";
global.__objectNames[13] = "wall_ob";
global.__objectNames[14] = "obj_coin";
global.__objectNames[15] = "object_start";
global.__objectNames[16] = "object_load";
global.__objectNames[17] = "object_bu_u";
global.__objectNames[18] = "object_bu_r";
global.__objectNames[19] = "object_bu_d";
global.__objectNames[20] = "object_bu_l";
global.__objectNames[21] = "object_drag_drop";


// create another array that has the correct entries
var len = array_length_1d(global.__objectDepths);
global.__objectID2Depth = [];
for( var i=0; i<len; ++i ) {
	var objID = asset_get_index( global.__objectNames[i] );
	if (objID >= 0) {
		global.__objectID2Depth[ objID ] = global.__objectDepths[i];
	} // end if
} // end for
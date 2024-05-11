with (object_en_big_hp) {
var __b__;
__b__ = action_if_variable(en_big_hp, 0, 3);
}
if __b__
{
{
action_kill_object();
with (object_en_big_hp) {
__b__ = action_if_variable(en_big_hp, 0, 3);
}
if __b__
{
action_sound(sound_vs_en_big_death, 0);
}
}
}

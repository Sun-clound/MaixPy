#include "obj.h"

const mp_obj_module_t my_lib_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_my_lib_globals_dict,
};
STATIC mp_obj_t hello()
{
    mp_printf(&mp_plat_print, "hello from my_lib");
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_0(my_lib_func_hello_obj, my_lib_func_hello);

STATIC const mp_map_elem_t my_lib_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_my_lib) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_hello), (mp_obj_t)&my_lib_func_hello_obj },

};

STATIC MP_DEFINE_CONST_DICT (
    mp_module_my_lib_globals_dict,
    my_lib_globals_table
);
typedef struct _mp_map_elem_t {
    mp_obj_t key;
    mp_obj_t value;
} mp_map_elem_t;
MP_REGISTER_MODULE(MP_QSTR_my_lib, my_lib_module, MODULE_MY_LIB_ENABLED);


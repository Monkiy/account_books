#include "component_manage.h"
#include "component_manage_private.h"

component_manage::component_manage() :
    __d_ptr(new component_manage_private)
{
}

bool component_manage::load_component(const QString & component_name, const QString & dll_file_name)
{
    return __d_ptr->load_component(component_name, dll_file_name);
}

QWidget * component_manage::find_component(const QString & component_name)
{
    return __d_ptr->find_component(component_name);
}

QObject * component_manage::find_data_object(const QString & component_name)
{
    return __d_ptr->find_data_object(component_name);
}

#include "component_manage_private.h"
#include <QLibrary>
#include "component.h"

//Q_DECLARE_METATYPE(QWidget*);
//Q_DECLARE_METATYPE(QObject*);

component_manage_private::component_manage_private()
{
}

bool component_manage_private::load_component(const QString & component_name, const QString & dll_file_name)
{
    QLibrary lib(dll_file_name);
    lib.load();
    if (lib.isLoaded())
        return false;
    fcreate_component f_create_component = reinterpret_cast<fcreate_component>(lib.resolve("create_component"));
    if (f_create_component)
    {
        QWidget* w = f_create_component();
        if (w)
            __component_hash.insert(component_name, QVariant::fromValue(w));
    }

    fcreate_data_object f_create_data_object = reinterpret_cast<fcreate_data_object>(lib.resolve("create_data_object"));
    if (f_create_data_object)
    {
        QObject* obj = f_create_data_object();
        if (obj)
            __data_object_hash.insert(component_name, QVariant::fromValue(obj));
    }

    if (!f_create_component && !f_create_data_object)
        return false;

    return true;
}

QWidget * component_manage_private::find_component(const QString & component_name)
{
    if (__component_hash.contains(component_name))
        return __component_hash.value(component_name).value<QWidget*>();
    return nullptr;
}

QObject * component_manage_private::find_data_object(const QString & component_name)
{
    if (__data_object_hash.contains(component_name))
        return __data_object_hash.value(component_name).value<QObject*>();
    return nullptr;
}

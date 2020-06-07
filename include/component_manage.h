#pragma once
#include <QtCore/qglobal.h>
#include <QtWidgets/QWidget>
#include <memory>

# if defined(COMPONENT_MANAGE_LIB)
#  define COMPONENT_MANAGE_EXPORT Q_DECL_EXPORT
# else
#  define COMPONENT_MANAGE_EXPORT Q_DECL_IMPORT
# endif

class component_manage_private;
class COMPONENT_MANAGE_EXPORT component_manage
{
public:
    component_manage();
    bool load_component(const QString& component_name, const QString& dll_file_name);
    QWidget* find_component(const QString& component_name);
    QObject* find_data_object(const QString& component_name);

private:
    std::shared_ptr<component_manage_private> __d_ptr;
private:
    Q_DISABLE_COPY(component_manage)
};

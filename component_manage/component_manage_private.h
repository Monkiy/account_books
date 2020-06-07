#pragma once
#include <QtWidgets/QWidget>
#include <QVariantHash>

class component_manage_private
{
public:
    component_manage_private();
    bool load_component(const QString& component_name, const QString& dll_file_name);
    QWidget* find_component(const QString& component_name);
    QObject* find_data_object(const QString& component_name);

private:
    QVariantHash __component_hash;//组件hash
    QVariantHash __data_object_hash;//数据对象hash
};
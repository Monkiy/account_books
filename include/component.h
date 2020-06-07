#pragma once
/*
组件接口定义

create_component
    创建组件界面

create_data_object
    创建组件数据对象
*/

#include <QtWidgets/QWidget>

extern "C" QWidget* create_component();
extern "C" QObject* create_data_object();

typedef QWidget* (*fcreate_component)();
typedef QObject* (*fcreate_data_object)();
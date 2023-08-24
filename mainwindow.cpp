#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbhelper.h"


#include<QStandardItem>
#include<QMap>


QMap<Qt::HANDLE, CDBHelper*> CDBHelper::databaseMap;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTable()
{
    auto temp_dbhelper = CDBHelper::GetInstance();
    int size = temp_dbhelper->getSize();
//    QSqlQuery query = dbs_->getAllData("users");

    // 设置ListView
    QStandardItemModel* model = new QStandardItemModel();

    /* 设置列数 */
    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "用户名");

    /* 设置行数 */
    model->setRowCount(size);
    //        model->setHeaderData(0, Qt::Vertical, "");

    ui->tableView->setModel(model);
    /* 行颜色交替显示 */
    ui->tableView->setAlternatingRowColors(true);
    /* 不允许在图形界面修改内容 */
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 遍历结果集，并添加记录到ListView
    temp_dbhelper->getAllData(model);

    ui->tableView->adjustSize();
    ui->tableView->show();
}

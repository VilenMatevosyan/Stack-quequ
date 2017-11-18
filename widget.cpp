#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <QString>
#include <QListWidget>
#include "stack.h"
#include "queue.h"

Stack NewStack;
Queue NewQueue;

Widget::Widget(QWidget *parent) :
QWidget(parent),
ui(new Ui::Widget)
{
ui->setupUi(this);
}

Widget::~Widget()
{
delete ui;
}

void Widget::on_pushButton_clicked()
    {
    if (ui->StackBox->isChecked()&& !ui->QueueBox->isChecked()){
    if (ui->textEdit->toPlainText().size() != 0){

        ui->listWidget->insertItem(0, ui->textEdit->toPlainText());
         NewStack.Push(ui->textEdit->toPlainText().toInt());
         ui->textEdit->clear();
         ui->textEdit->setFocus();

}
}
    else if (ui->QueueBox->isChecked() && !ui->StackBox->isChecked()){
    if (ui->textEdit->toPlainText().size() != 0){
        ui->listWidget_2->addItem(ui->textEdit->toPlainText());
         NewQueue.Push(ui->textEdit->toPlainText().toInt());
         ui->textEdit->clear();
         ui->textEdit->setFocus();
         }
         }
    else if (ui->QueueBox->isChecked() && ui->StackBox->isChecked()){
        if (ui->textEdit->toPlainText().size() != 0){
            ui->listWidget_2->addItem(ui->textEdit->toPlainText());
             NewQueue.Push(ui->textEdit->toPlainText().toInt());
             ui->listWidget->insertItem(0, ui->textEdit->toPlainText());
              NewStack.Push(ui->textEdit->toPlainText().toInt());
              ui->textEdit->clear();
              ui->textEdit->setFocus();
}
    }
        }

    void Widget::on_PopButton_clicked()
{
    if ( ui->StackBox->isChecked()){
        if(ui->listWidget->count() > 0)
         {
         ui->label->setText(QString::number (NewStack.Pop(), 10));
         delete ui->listWidget->item(0);
         }
         }
    if ( ui->QueueBox->isChecked()){
        if(ui->listWidget_2->count() > 0) //Queue
         {
         ui->label_2->setText(QString::number (NewQueue.Pop(), 10));
         delete ui->listWidget_2->item(0);
         }
         }
        }



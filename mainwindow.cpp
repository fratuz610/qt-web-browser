#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QWebFrame>

MainWindow::MainWindow(int argc, char *argv[], QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(argc < 4)
        exit(-1);

    bool ok;
    QString widthStr(argv[1]);
    int width = widthStr.toInt(&ok);
    if(!ok) {
        qDebug() << "Invalid width'" << argv[1] << "'";
        exit(-1);
    }

    QString heightStr(argv[2]);
    int height = heightStr.toInt(&ok);

    if(!ok) {
        qDebug() << "Invalid height'" << argv[1] << "'";
        exit(-1);
    }

    QString url(argv[3]);

    qDebug() << "Called with width:" << width << "height" << height << "url" << url;

    this->setFixedSize(width, height);
    ui->centralWidget->setFixedSize(width, height);
    ui->webView->setFixedSize(width, height);
    ui->webView->setUrl(url);
    ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    //this->setWindowFlags(Qt::FramelessWindowHint);

    ui->webView->page()->action(QWebPage::Reload)->setVisible(false);
    ui->webView->page()->action(QWebPage::Forward)->setVisible(false);
    ui->webView->page()->action(QWebPage::Back)->setVisible(false);
    ui->webView->page()->action(QWebPage::Stop)->setVisible(false);
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
}

MainWindow::~MainWindow()
{
    delete ui;
}

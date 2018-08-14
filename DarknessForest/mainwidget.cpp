#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->menuWidget);
    connect(ui->newGemeButton, SIGNAL(clicked(bool)),
            this, SLOT(newGame()));
    connect(ui->loadGameButton, SIGNAL(clicked(bool)),
            this, SLOT(loadGame()));
    connect(ui->saveGameButton, SIGNAL(clicked(bool)),
            this, SLOT(saveGame()));
    connect(ui->exitGameButton, SIGNAL(clicked(bool)),
            this, SLOT(close()));   
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::newGame()
{
    ui->stackedWidget->setCurrentWidget(ui->newGameWidget);
}

void MainWidget::loadGame()
{
    ui->stackedWidget->setCurrentWidget(ui->loadGameWidget);
}

void MainWidget::saveGame()
{
    ui->stackedWidget->setCurrentWidget(ui->saveGameWidget);
}

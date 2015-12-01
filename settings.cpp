#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    resize(300, 300);
    setWindowFlags(Qt::FramelessWindowHint);
    init();
}

void Settings::mousePressEvent(QMouseEvent *me)
{
    coorX = me->x();
    coorY = me->y();
}

void Settings::mouseMoveEvent(QMouseEvent *me)
{
    move(me->globalX() - coorX, me->globalY() - coorY);
}

void Settings::init()
{
    //create buttons
    btn_OK = new QPushButton(tr("OK"));
    btn_Cancel = new QPushButton(tr("Cancel"));

    //create sliders
    slider_hue = new QSlider(Qt::Vertical);
    slider_sturation = new QSlider(Qt::Vertical);
    slider_video_size = new QSlider(Qt::Vertical);
    slider_video_control = new QSlider(Qt::Vertical);

    //create groupbox
    color_Settings = new QGroupBox(tr("Color Settings"), this);
    video_Settings = new QGroupBox(tr("Video Settings"), this);

    //create layout
    master_layout = new QHBoxLayout;
    button_layout = new QHBoxLayout;
    color_layout = new QHBoxLayout;
    video_layout = new QHBoxLayout;

    //button setup
    button_layout->addWidget(btn_OK);
    button_layout->addWidget(btn_Cancel);

    //groupbox setup
    //color_Settings->

    //slider setup
    slider_hue = new QSlider(Qt::Horizontal);
    slider_sturation = new QSlider(Qt::Horizontal);
    slider_video_control = new QSlider(Qt::Horizontal);
    slider_video_size = new QSlider(Qt::Horizontal);

    //add item into layout
    color_layout->addWidget(slider_hue);
    color_layout->addWidget(slider_sturation);

    video_layout->addWidget(slider_video_size);
    video_layout->addWidget(slider_video_control);

    master_layout->addLayout(button_layout);
    master_layout->addLayout(color_layout);
    master_layout->addLayout(video_layout);

    //add main layour
    setLayout(master_layout);
    actionAll();
}

void Settings::actionAll()
{
    connect(btn_Cancel,SIGNAL(clicked(bool)), this, SLOT(close()));
}




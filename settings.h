#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include <QSlider>
#include <QGroupBox>
#include <QHBoxLayout>

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);

signals:

public slots:

private:

    //objects
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QGroupBox *color_Settings;
    QGroupBox *video_Settings;
    QHBoxLayout *master_layout;
    QHBoxLayout *button_layout;
    QHBoxLayout *color_layout;
    QHBoxLayout *video_layout;
    QSlider *slider_hue;
    QSlider *slider_sturation;
    QSlider *slider_video_size;
    QSlider *slider_video_control;

    //coordinates
    int coorX;
    int coorY;

    //mouse move and press events
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);

    //create all
    void init();
    void actionAll();
};

#endif // SETTINGS_H

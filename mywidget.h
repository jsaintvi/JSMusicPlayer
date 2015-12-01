#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QSpacerItem>
#include <QFileDialog>
#include <QMessageBox>

class MediaWindow : public QWidget
{
    Q_OBJECT

public:
    MediaWindow();
    ~MediaWindow();

private slots:
    void on_open_file();
    void on_play();
    void on_pause();
    void on_settings();
    void on_minmax();
    void on_stop();
    void on_volume();
    void on_setVolume(int value);
    void on_Exit();

private:

    //declare object of classes
    MediaWindow *ui;
    QPushButton *btn_play;
    QPushButton *btn_pause;
    QPushButton *btn_stop;
    QPushButton *btn_close;
    QPushButton *btn_volume;
    QPushButton *btn_open;
    QPushButton *btn_settings;
    QPushButton *btn_minmax;
    QMediaPlayer *media_player;
    QVideoWidget *video_widget;
    QHBoxLayout *buttonlab;
    QHBoxLayout *buttonlab2;
    QVBoxLayout *videolab;
    QVBoxLayout *mainlab;
    QSlider *slider_Seek;
    QSlider *slider_Volume;
    QLabel *lbl_time;

    //atributes
    int coorX;
    int coorY;
    QString filepath;

    //required functions
    void mouseMoveEvent(QMouseEvent *me);
    void mousePressEvent(QMouseEvent *me);
    void mouseDoubleClickEvent(QMouseEvent *me);
    void addComponents();
    void playVideo(QString path);
    void setConnection();
};
#endif // WIDGET_H

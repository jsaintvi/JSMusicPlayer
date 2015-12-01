/*
 * Jodex Music Player
 * simple audio/video player
 * play most of videos
 * open your desire files
 * play the file(s)
 * play from internet
*/

#include "mywidget.h"
#include "settings.h"

MediaWindow::MediaWindow() {

    //setup of the main window
    resize(600,600);
    setWindowTitle("Jodex Music Player");
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QWidget{background-color: #333;}");

    //create all buttons
    btn_play = new QPushButton;
    btn_play->setStyleSheet("QPushButton{qproperty-icon: url(:/play.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_pause = new QPushButton;
    btn_pause->setStyleSheet("QPushButton{qproperty-icon: url(:/pause.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_stop = new QPushButton;
    btn_stop->setStyleSheet("QPushButton{qproperty-icon: url(:/stop.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_close = new QPushButton;
    btn_close->setStyleSheet("QPushButton{qproperty-icon: url(:/delete.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_volume = new QPushButton;
    btn_volume->setStyleSheet("QPushButton{qproperty-icon: url(:/sound.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_open = new QPushButton;
    btn_open->setStyleSheet("QPushButton{qproperty-icon: url(:/open file.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_settings = new QPushButton;
    btn_settings->setStyleSheet("QPushButton{qproperty-icon: url(:/settings.png); border: none;} QPushButton::hover{background-color: green;}");
    btn_minmax = new QPushButton("+/-");
    btn_minmax->setStyleSheet("QPushButton{color: #fff; border: none;} QPushButton::hover{background-color: green;}");

    //create media objects
    media_player = new QMediaPlayer;
    video_widget = new QVideoWidget;

    //create layouts
    buttonlab = new QHBoxLayout;
    buttonlab2 = new QHBoxLayout;
    videolab = new QVBoxLayout;
    mainlab = new QVBoxLayout;
    mainlab->setStretch(x(), y());

    //creae sliders
    slider_Seek = new QSlider(Qt::Horizontal);
    slider_Volume = new QSlider(Qt::Horizontal);
    slider_Volume->setMinimum(0);
    slider_Volume->setValue(40);
    slider_Volume->setMaximum(100);

    //create labels
    lbl_time = new QLabel;

    //add componets
    addComponents();
}

//destroy widget when work finish
MediaWindow::~MediaWindow()
{
    delete this;
}

void MediaWindow::mouseMoveEvent(QMouseEvent *me)
{
    //move this coordinates
    move(me->globalX() - coorX, me->globalY() - coorY);
}

void MediaWindow::mousePressEvent(QMouseEvent *me)
{
    //get the position of mouse pointer
    coorX = me->x();
    coorY = me->y();
}

void MediaWindow::mouseDoubleClickEvent(QMouseEvent *me)
{
    //fullsreen if press double clicked
    if(me->MouseButtonDblClick){
        if(!this->isFullScreen()){
            this->showFullScreen();
        } else {
            this->showNormal();
        }
    }
}

void MediaWindow::addComponents()
{
    //bottom button box
    buttonlab->addWidget(btn_play);
    buttonlab->addWidget(btn_pause);
    buttonlab->addWidget(btn_stop);
    buttonlab->addWidget(slider_Seek);
    buttonlab->addWidget(btn_volume);
    buttonlab->addWidget(slider_Volume);

    //top button box
    buttonlab2->addWidget(btn_open);
    buttonlab2->addWidget(btn_settings);
    buttonlab2->addWidget(btn_minmax);
    buttonlab2->addWidget(btn_close);

    //middle video widget
    videolab->addWidget(video_widget);

    //main layout setup
    mainlab->addLayout(buttonlab2);
    mainlab->addLayout(videolab);
    mainlab->addLayout(buttonlab);

    //show whole things
    setLayout(mainlab);

    //add signal and slots
    setConnection();
}

void MediaWindow::playVideo(QString path)
{
    media_player->setMedia(QUrl::fromLocalFile(path));
    media_player->setVideoOutput(video_widget);
    media_player->play();
}

void MediaWindow::setConnection()
{
    //connect signal and slots into widgets
    connect(btn_play, SIGNAL(clicked(bool)), this, SLOT(on_play()));
    connect(btn_pause, SIGNAL(clicked(bool)), this, SLOT(on_pause()));
    connect(btn_stop, SIGNAL(clicked(bool)), this, SLOT(on_stop()));
    connect(btn_settings, SIGNAL(clicked(bool)), this, SLOT(on_settings()));
    connect(slider_Seek, SIGNAL(clicked(bool)), media_player, SLOT(setPosition(qint64)));
    connect(slider_Volume, SIGNAL(valueChanged(int)), media_player, SLOT(setVolume(int)));
    connect(btn_close, SIGNAL(clicked(bool)), this, SLOT(on_Exit()));
    connect(btn_open, SIGNAL(clicked(bool)), this, SLOT(on_open_file()));
    connect(btn_minmax, SIGNAL(clicked(bool)), this, SLOT(on_minmax()));
    connect(btn_volume, SIGNAL(clicked(bool)), this, SLOT(on_volume()));
}

void MediaWindow::on_open_file()
{
    filepath = QFileDialog::getOpenFileName(this,tr("Open Media File"), "/home",
                                            tr("Media Files (*.mp3 *.mp4 *.wav "
                                               "*.mpeg *.avi *.flv*.amr *.vob *.mkv)"));
}

void MediaWindow::on_play()
{
    if(!filepath.isEmpty()) {
        playVideo(filepath);
        btn_play->setEnabled(false);
        btn_pause->setEnabled(true);
        btn_stop->setEnabled(true);
    } else {
        QMessageBox::warning(this, "File not found!!!", "Please Select a media file from open button.", QMessageBox::Ok);
    }
}

void MediaWindow::on_pause()
{
    media_player->pause();
    btn_play->setEnabled(true);
    btn_stop->setEnabled(true);
    btn_pause->setEnabled(false);
}

void MediaWindow::on_settings()
{
    Settings *set = new Settings;
    set->show();
}

void MediaWindow::on_minmax()
{
    //fullsreen if press double clicked
    if(!this->isFullScreen()){
            this->showFullScreen();
        } else {
            this->showNormal();
        }

}

void MediaWindow::on_stop()
{
    media_player->stop();
    btn_stop->setEnabled(false);
    btn_play->setEnabled(true);
    btn_pause->setEnabled(false);
    media_player->destroyed(this);
}

void MediaWindow::on_volume()
{
    if(!media_player->isMuted()){
        media_player->setMuted(true);
        btn_volume->setEnabled(false);
        slider_Volume->setEnabled(false);
    } else {
        media_player->setMuted(false);
        slider_Volume->setEnabled(true);
        btn_volume->setEnabled(true);
    }
}

void MediaWindow::on_setVolume(int value)
{
    media_player->setVolume(value);
}

void MediaWindow::on_Exit()
{
    this->close();
}

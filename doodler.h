#ifndef DOODLER_H
#define DOODLER_H
#include <iostream>
#include <QVector>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <iomanip>
#include <QTextStream>
#include <QFile>
#include <QDateTime>
#include <QTimer>
#include <QObject>
#include <cstdlib>
#include <ctime>
#include <string>
#include <QList>
#include <QTest>
#include <QPushButton>
#include "blueplatform.h"
#include "grayplatform.h"
#include "brownplatform.h"
#include "spring.h"
#include "jetpack.h"
#include "monster2.h"
#include "monster3.h"
#include "bullet.h"
#include "blackhole.h"
#include "protectshield.h"

class Doodler : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Doodler();
    ~Doodler();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void firstSpawn();    
    std::string object_type = "Doodler";
signals:
    void tooHigh(int down_dist);
    void gameOverSignal(int point);
public slots:
    void addJump();
    void newPlatform(int exceed_dist);
    void clickPause();
    void timing();
private:
    bool SpawnPlat(int x, int y);
    bool collideOtherPlat(QGraphicsItem *ptr);
    int countPlatform();
    void moveRight();
    void moveLeft();
    void changePos();
    void checkCollide();
    void stepPlatform();
    void stepSpring();
    void touchJetpack();
    void touchShield();
    void createItem();
    void decidePlatNum();    
    void shootBullet();    
    int jump_frame = 0, jump_frame2 = 0, shield_frame = 0;
    int point = 0, up_state = 0;
    int minute = 0, second = 0;
    int last_y = 720, platform_num = 12;
    bool right = false, left = false, is_shild = false, is_pause = false;
    bool create_rocket = false, create_hazard = false, create_shield = false;
    bool create_brown = false;
    QPixmap pic_right, pic_left, rocket_right, rocket_left, pic_shoot;
    QPixmap shield_right, shield_left;
    QList<QGraphicsItem*> temp_list;
    QTimer *timer, *timer2;
    QGraphicsTextItem *point_text, *time_text;
    QIcon pause_icon, play_icon;
    QPushButton *pause_button;
    QString minute_text, second_text;
    QVector<QPointF> pos_vec;
};

#endif // DOODLER_H

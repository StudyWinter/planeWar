#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QSound>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化场景
    initScene();
    // 启动游戏
    playGame();
}

MainScene::~MainScene()
{
}

// 初始化游戏场景
void MainScene::initScene()
{
    // 添加随机数种子
    srand((unsigned int)time(NULL));

    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    // 加载图片
    setWindowIcon(QIcon(GAME_ICON));    
    // 定时器设置
    m_timer.setInterval(GAME_RATE);
    // 敌机出场间隔
    m_recorder = 0;
    // 初始化计分为0
    m_count = 0;
}

// 启动游戏  用于启动定时器对象
void MainScene::playGame()
{
    // 启动定时器
    m_timer.start();
    // 添加背景音乐
    QSound::play(SOUND_BACKGROUNG);


    // 监听定时器
    connect(&m_timer, &QTimer::timeout, this, [=]() {
        // 敌机出场
        enemyToScene();

        // 更新游戏中元素的坐标
        updatePosition();
        // 重新绘制地图
        update();
        // 碰撞检测
        collisionDetection();
    });
}

// 更新坐标
void MainScene::updatePosition()
{
    // 更新地图坐标
    m_map.mapPosition();

    // 发射子弹
    m_hero.shoot();

    // 计算子弹坐标
    for (int i = 0; i < BULLET_NUM; i++) {
        // 如果子弹是非空状态，计算发射位置
        if (m_hero.m_bullets[i].m_free == false) {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    // 计算敌机坐标
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_free == false) {
            m_enemys[i].updatePosition();
        }
    }

    // 计算爆炸播放的图片
    for (int i = 0; i < BOMB_NUM; i++) {
        if (m_bombs[i].m_free == false) {
            m_bombs[i].updateInfo();
        }
    }
}

// 绘图事件
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0, m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY , m_map.m_map2);

    // 绘制英雄飞机
    painter.drawPixmap(m_hero.m_x, m_hero.m_y, m_hero.m_plane);

    // 绘制子弹
    for (int i = 0; i < BULLET_NUM; i++) {
        // 如果子弹是非空状态，计算发射位置
        if (m_hero.m_bullets[i].m_free == false) {
            painter.drawPixmap(m_hero.m_bullets[i].m_x, m_hero.m_bullets[i].m_y, m_hero.m_bullets[i].m_bullet);
        }
    }

    // 绘制敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_free == false) {
            painter.drawPixmap(m_enemys[i].m_x, m_enemys[i].m_y, m_enemys[i].m_enemy);
        }
    }

    // 绘制爆炸图片
    for (int i = 0; i < BOMB_NUM; i++) {
        if (m_bombs[i].m_free == false) {
            painter.drawPixmap(m_bombs[i].m_x, m_bombs[i].m_y, m_bombs[i].m_pixarr[m_bombs[i].m_index]);
        }
    }


    // 绘制计分
    painter.setFont(QFont("宋体", 15));         // 设置字体字号
    painter.setPen(QColor(Qt::red));
    painter.drawText(0, 30, QString("得分:"));
    QString str = QString::number(m_count);
    painter.drawText(80, 30, str);
}

// 鼠标移动事件
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_rect.width() * 0.5;       // 鼠标的位置 - 飞机矩形的一半
    int y = event->y() - m_hero.m_rect.height() * 0.5;

    // 边界检查
    if (x <= 0) {
        x = 0;
    }
    if (x >= GAME_WIDTH - m_hero.m_rect.width()) {
        x = GAME_WIDTH - m_hero.m_rect.width();
    }

    if (y <= 0) {
        y = 0;
    }
    if (y >= GAME_HEIGHT - m_hero.m_rect.height()) {
        y = GAME_HEIGHT - m_hero.m_rect.height();
    }
    m_hero.setPosition(x, y);
}

// 敌机出场
void MainScene::enemyToScene()
{
    m_recorder++;
    if (m_recorder < ENEMY_INYERVAl) {
        return;
    }

    m_recorder = 0;
    for (int i = 0; i < ENEMY_NUM; i++) {
        // 是空闲状态
        if (m_enemys[i].m_free == true) {
            m_enemys[i].m_free = false;

            // 设置坐标
            m_enemys[i].m_x = rand() % (GAME_WIDTH - m_enemys[i].m_rect.width());
            m_enemys[i].m_y = -m_enemys[i].m_rect.height();
            break;
        }
    }
}

// 检测碰撞
void MainScene::collisionDetection()
{
    // 遍历所有非空闲敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_free) {
            // 空闲敌机
            continue;
        }

        // 遍历所有非空闲子弹
        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_hero.m_bullets[j].m_free) {
                // 空闲子弹
                continue;
            }

            // 如果子弹矩形和敌机矩形相交，发生碰撞，同时变为空闲状态
            if (m_enemys[i].m_rect.intersects(m_hero.m_bullets[j].m_rect)) {
                m_enemys[i].m_free = true;
                m_hero.m_bullets[j].m_free = true;

                // 爆炸音乐
                QSound::play(SOUND_BOMB);
                m_count += 5;
                qDebug() << "计分:" << m_count;

                // 播放爆炸效果
                for (int k = 0; k < BOMB_NUM; k++) {
                    if (m_bombs[k].m_free) {
                        // 设置爆炸状态为非空闲
                        m_bombs[k].m_free = false;

                        // 更新坐标
                        m_bombs[k].m_x = m_enemys[i].m_x;
                        m_bombs[k].m_y = m_enemys[i].m_y;
                        break;
                    }
                }


            }

        }

    }
}


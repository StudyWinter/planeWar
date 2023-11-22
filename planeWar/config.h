#ifndef CONFIG_H
#define CONFIG_H


/***********************游戏数据配置***********************************/
#define GAME_WIDTH  512                             // 宽度
#define GAME_HEIGHT 768                             // 高度
#define GAME_TITLE "飞机大战 v1.0"                   // 标题
#define GAME_RES_PATH "./plane.rcc"                 // 资源路径
#define GAME_ICON ":/res/app.ico"                   // 图标路径

/*************************地图信息***********************************/
#define MAP_PATH ":/res/img_bg_level_3.jpg"         // 地图1图片路径
#define MAP_SCROLL_SPEED 2                          // 地图滚动速度


#define GAME_RATE  10                               //刷新间隔，帧率 单位毫秒

/************************飞机配置数据***********************************/
#define HERO_PATH ":/res/hero2.png"                 // 飞机图片路径


/************************子弹配置数据***********************************/
#define BULLET_PATH ":/res/bullet_11.png"           // 子弹图片路径
#define BULLET_SPEED 5                              // 子弹移动速度
#define BULLET_NUM 30                               // 弹匣中子弹总数
#define BULLET_INTERVAL 20                          // 发射子弹时间间隔


/************************敌机配置数据***********************************/
#define ENEMY_PATH ":/res/img-plane_5.png"          // 敌机图片路径
#define ENEMY_SPEED 3                               // 敌机移动速度
#define ENEMY_NUM 20                                // 敌机总数量
#define ENEMY_INYERVAl 30                           // 敌机出场时间间隔


/************************敌机发射子弹***********************************/
#define ENEMY_BULLET_PATH ":/res/bullet_4.png"      // 敌机子弹图片路径
#define ENEMY_BULLET_SPEED 5                        // 敌机子弹移动速度
#define ENEMY_BULLET_NUM 15                         // 每个敌机弹匣中子弹总数
#define ENEMY_BULLET_INTERVAL 40                    // 每个敌机发射子弹时间间隔




/************************爆炸配置数据***********************************/
#define BOMB_PATH ":/res/bomb-%1.png"               // 爆炸图片路径
#define BOMB_NUM 20                                 // 爆炸数量
#define BOMB_MAX 7                                  // 爆炸图片最大索引
#define BOMB_INTERVAl 20                            // 爆炸切图时间间隔

/************************音效配置数据***********************************/
#define SOUND_BACKGROUNG ":/res/bg.wav"             // 背景音乐
#define SOUND_BOMB ":/res/bomb.wav"                 // 爆炸音效


#endif // CONFIG_H

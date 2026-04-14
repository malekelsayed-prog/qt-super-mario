#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem ground(0, 0, 300, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });
  timer.start(33);

  QGraphicsRectItem platform2(0, 0, 200, 20);
  platform2.setBrush(Qt::darkGreen);
  platform2.setPos(500, 200);
  scene.addItem(&platform2);

  QGraphicsRectItem platform3(0, 0, 200, 20);
  platform3.setBrush(Qt::darkGreen);
  platform3.setPos(900, 150);
  scene.addItem(&platform3);

  return app.exec();
}

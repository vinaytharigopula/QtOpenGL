#include "DuCoralScene.h"
#include "DuThread.h"
#include "DuCoralCharacter.h"
#include "DuDefines.h"
#include "DuUtil.h"
#include <QPixmap>

DuCoralScene::DuCoralScene(QObject *parent)
    : QGraphicsScene(0, 0, X_SIZE, Y_SIZE, parent)
{
    mThread = new DuThread(35, this);

    QPixmap background(":coral.jpeg");
    background = background.scaled(X_SIZE, Y_SIZE);
    addPixmap(background);

    QStringList characters = { ":fish1.png", ":fish2.png", ":horse.png",
                               ":shark1.png", ":shark2.png" };
    for (const auto &iChar : characters) {
        QPixmap pixmap(iChar);
        int x, y, vx, vy;
        x = DuRandom(0, X_SIZE - pixmap.width());
        y = DuRandom(0, Y_SIZE - pixmap.height());
        vx = DuRandom(3, 5);
        vy = DuRandom(3, 5);
        auto character = new DuCoralCharacter(pixmap, x, y, vx, vy);
        addItem(character);
        mCharacters.append(character);
    }

    connect(mThread, &DuThread::timeOut, [&]() {
        for (const auto &iChar : mCharacters) {
            int x, y;
            x = iChar->get_x();
            y = iChar->get_y();
            // controlar límites de la pantalla
            if (x <= 0 || (x + iChar->get_w()) >= X_SIZE) {
                iChar->set_vx(-iChar->get_vx());
            }
            if (y <= 0 || (y + iChar->get_h()) >= Y_SIZE) {
                iChar->set_vy(-iChar->get_vy());
            }
            // controlar colisión con otros personajes
            // TODO: ...
            x += iChar->get_vx();
            y += iChar->get_vy();
            iChar->set_x(x);
            iChar->set_y(y);
        }
        update();
    });

    mThread->start();
}


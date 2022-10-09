#ifndef DUCORALSCENE_H
#define DUCORALSCENE_H

#include <QGraphicsScene>

class DuThread;
class DuCoralCharacter;

class DuCoralScene : public QGraphicsScene
{
public:
    DuCoralScene(QObject *parent = nullptr);
private:
    DuThread *mThread; // temporizador
    QList<DuCoralCharacter *> mCharacters; // personajes
};

#endif // DUCORALSCENE_H

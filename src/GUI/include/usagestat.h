#ifndef USAGESTAT_H
#define USAGESTAT_H

#include <QObject>
#include <QFile>
#include <QDebug>

class CpuUsage : public QObject
{
    Q_OBJECT
public:
    explicit CpuUsage(QObject *parent = nullptr) : QObject(parent), prevIdleTime(0), prevTotalTime(0) { }


private:
    int prevIdleTime;
    int prevTotalTime;

signals:

public slots:

protected:
    virtual void timerEvent(QTimerEvent *)
    {
        QFile file("/proc/stat");
        file.open(QFile::ReadOnly);
        const QList<QByteArray> times = file.readLine().simplified().split(' ').mid(1);
        const int idleTime = times.at(3).toInt();
        int totalTime = 0;
        foreach (const QByteArray &time, times) {
            totalTime += time.toInt();
        }
        qInfo("%5.1f%%", (1 - (1.0*idleTime-prevIdleTime) / (totalTime-prevTotalTime)) * 100.0);
        prevIdleTime = idleTime;
        prevTotalTime = totalTime;
    }
};

#endif // USAGESTAT_H

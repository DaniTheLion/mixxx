#ifndef BASEEXTERNALLIBRARYFEATURE_H
#define BASEEXTERNALLIBRARYFEATURE_H

#include <QAction>
#include <QModelIndex>

#include "library/libraryfeature.h"

class BaseSqlTableModel;
class TrackCollection;

class BaseExternalLibraryFeature : public LibraryFeature {
    Q_OBJECT
  public:
    BaseExternalLibraryFeature(QObject* pParent, TrackCollection* pCollection);
    virtual ~BaseExternalLibraryFeature();

  public slots:
    virtual void onRightClick(const QPoint& globalPos);
    virtual void onRightClickChild(const QPoint& globalPos, QModelIndex index);

  protected:
    virtual BaseSqlTableModel* getPlaylistModelForPlaylist(QString playlist) = 0;
    virtual void appendTrackIdsFromRightClickIndex(QList<int>* trackIds, QString* pPlaylist);

    QModelIndex m_lastRightClickedIndex;

  private slots:
    void slotAddToAutoDJ();
    void slotAddToAutoDJTop();
    virtual void slotImportAsMixxxPlaylist();

  private:
    virtual void addToAutoDJ(bool bTop);

    TrackCollection* m_pTrackCollection;
    QAction* m_pAddToAutoDJAction;
    QAction* m_pAddToAutoDJTopAction;
    QAction* m_pImportAsMixxxPlaylistAction;
};

#endif /* BASEEXTERNALLIBRARYFEATURE_H */

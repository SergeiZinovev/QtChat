/**
\file ChatWindow.h
\brief GUI chat main window

Handles user interface to send and get message, log out and remove account
*/

#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QTimer>
#include "Client.h"


namespace Ui {
  class ChatWindow;
}

class ChatWindow : public QWidget{
  Q_OBJECT

  public:
    explicit ChatWindow(QWidget* parent = nullptr);
    ~ChatWindow();

    void setClient(Client* client);
    void connectNetworkSignal_UpdateMessage();

  signals:
    void toLogin();

  public slots:
    void setUserLogin(const std::string& userLogin);

    void handleServerResponse_GetUsersList();
    void handleServerResponse_GetChat();
    void handleServerResponse_GetPrivateChat();

  private slots:
    void on_pushButton_SendToAll_clicked();
    void on_pushButton_SendPrivate_clicked();
    void on_pushButton_Logout_clicked();
    void on_pushButton_DeleteAccount_clicked();

  private:
    void connectNetworkSignal_GetUserList();
    void disconnectNetworkSignal_GetUserList();

    void disconnectNetworkSignal_UpdateMessage();

    void connectNetworkSignal_GetChat();
    void disconnectNetworkSignal_GetChat();

    void connectNetworkSignal_GetPrivateChat();
    void disconnectNetworkSignal_GetPrivateChat();

    void updateMessages();

    void displayMessages();

    Ui::ChatWindow* ui;
    std::string userLogin_; //Current user login
    Client* client_; //To send and get requests to server
    QTimer* timer_; //To update messages on the screen by timeout
    QString chat_; //To store server response - messages for all users
    QString privateChat_; //To store server response - private messages for current user
};

#endif // CHATWINDOW_H

#ifndef ADMINLOGINVIEWMODEL_HPP
#define ADMINLOGINVIEWMODEL_HPP

#include <QObject>
#include <QString>

namespace Hedral
{
    namespace UI
    {
        class AdminLoginViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString email READ Email WRITE Email NOTIFY EmailChanged);
            Q_PROPERTY(QString password READ Password WRITE Password NOTIFY PasswordChanged);

        public:
            explicit AdminLoginViewModel(QObject* parent = nullptr);

        public:
            [[nodiscard]]
            QString Email() const;
            void Email(const QString& email);

            [[nodiscard]]
            QString Password() const;
            void Password(const QString& email);

        signals:
            void EmailChanged();
            void PasswordChanged();

        public slots:

        private:
            QString m_email;
            QString m_password;
        };
    }
}

#endif

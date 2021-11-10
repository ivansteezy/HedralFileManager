#ifndef SIGNUPVIEWMODEL_HPP
#define SIGNUPVIEWMODEL_HPP

#include <QObject>
#include <QString>

namespace Hedral
{
    namespace UI
    {
        class SignUpViewModel : public QObject
        {
            Q_OBJECT;

            Q_PROPERTY(QString name READ Name WRITE Name NOTIFY NameChanged);
            Q_PROPERTY(QString lastName READ LastName WRITE LastName NOTIFY LastNameChanged);
            Q_PROPERTY(QString password READ Password WRITE Password NOTIFY PasswordChanged);
            Q_PROPERTY(QString confirmPassword READ ConfirmPassword WRITE ConfirmPassword NOTIFY ConfirmPasswordChanged);
            Q_PROPERTY(QString level READ Level WRITE Level NOTIFY LevelChanged);

        public:
            explicit SignUpViewModel(QObject* parent = nullptr);

        public:
            [[nodiscard]]
            QString Name() const;
            void Name(const QString& name);

            [[nodiscard]]
            QString LastName() const;
            void LastName(const QString& lastName);

            [[nodiscard]]
            QString Password() const;
            void Password(const QString& password);

            [[nodiscard]]
            QString ConfirmPassword() const;
            void ConfirmPassword(const QString& confirmPassword);

            [[nodiscard]]
            QString Level() const;
            void Level(const QString& level);

        signals:
            void NameChanged();
            void LastNameChanged();
            void PasswordChanged();
            void ConfirmPasswordChanged();
            void LevelChanged();

        public slots:

        private:
            QString m_name;
            QString m_lastName;
            QString m_password;
            QString m_confirmPassword;
            QString m_level;
        };
    }
}

#endif

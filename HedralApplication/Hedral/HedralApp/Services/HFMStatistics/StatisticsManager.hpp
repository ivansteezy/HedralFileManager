#ifndef STATISTICSMANAGER_HPP
#define STATISTICSMANAGER_HPP

#include "StatisticsBase.hpp"

namespace Hedral
{
    namespace Stats
    {
        class StatisticsManagerImpl : public QObject, public Core::Implements<IStatisticsManager, Hedral::Core::IQtObjectSupport>
        {
            Q_OBJECT;

        public:
            StatisticsManagerImpl();
            virtual ~StatisticsManagerImpl();

            virtual void GenerateStatistics() override;
            virtual uint32_t GetNumberOfWords() const override;
            virtual uint32_t GetNumberOfCoincidences() const override;
            virtual uint32_t GetNumberOfParaphs() const override;
            virtual uint32_t GetNumberOfLines() const override;

            virtual QObject* AsQtObject() override;
            virtual const QMetaObject* MetaObject() override;
        };
    }
}

#endif

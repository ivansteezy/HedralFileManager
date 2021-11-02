#include "StatisticsManager.hpp"

using namespace Hedral::Stats;

HEDRAL_IMPLEMENT_CLASSFACTORY(StatisticsManager, StatisticsManagerImpl, IStatisticsManager);

StatisticsManagerImpl::StatisticsManagerImpl()
{

}

StatisticsManagerImpl::~StatisticsManagerImpl()
{

}


void StatisticsManagerImpl::GenerateStatistics()
{

}


uint32_t StatisticsManagerImpl::GetNumberOfWords() const
{
    return 0;
}

uint32_t StatisticsManagerImpl::GetNumberOfCoincidences() const
{
    return 0;
}

uint32_t StatisticsManagerImpl::GetNumberOfParaphs() const
{
    return 0;
}

uint32_t StatisticsManagerImpl::GetNumberOfLines() const
{
    return 0;
}

QObject* StatisticsManagerImpl::AsQtObject()
{
    return static_cast<QObject*>(this);
}

const QMetaObject* StatisticsManagerImpl::MetaObject()
{
    return this->metaObject();
}

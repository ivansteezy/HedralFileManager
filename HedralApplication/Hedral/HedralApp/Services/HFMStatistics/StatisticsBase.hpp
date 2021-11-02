#ifndef STATISTICSBASE_HPP
#define STATISTICSBASE_HPP

#include "../HFMCore/HedralCore.hpp"

namespace Hedral
{
    namespace Stats
    {
        struct IStatisticsManager : Hedral::Core::IContract
        {
            HEDRAL_DECLARE_INTERFACE(IStatisticsManager, "IStatisticsManager");

            virtual void GenerateStatistics() = 0;
            virtual uint32_t GetNumberOfWords() const = 0;
            virtual uint32_t GetNumberOfCoincidences() const = 0;
            virtual uint32_t GetNumberOfParaphs() const = 0;
            virtual uint32_t GetNumberOfLines() const = 0;
        };
        HEDRAL_DECLARE_CLASSFACTORY(StatisticsManager, IStatisticsManager);

        struct GlobalStatisticsManager
        {
            static void SetInstance(Hedral::Core::ComPtr<IStatisticsManager> logger);
            static IStatisticsManager* Instance();
        };
    }
}

#endif

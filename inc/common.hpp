#pragma once

#ifdef MOCK_ENABLE
#define MOCKABLE virtual
#else
#define MOCKABLE
#endif

#ifdef TESTING
#define PRIVATE public
#else
#define PRIVATE private
#endif
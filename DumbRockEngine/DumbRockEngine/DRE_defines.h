#ifndef _DRE_DEFINES_H
#define _DRE_DEFINES_H

#pragma once

namespace DRE
{
//Pointer Delete Macro
#define P_DELETE(x) { delete x; x = nullptr; }
}

#endif
#include "Headers/ToolBox.h"

int main() {                                               // ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ⁺ ⁻ ⁼ ⁽ ⁾
    // cout << Bold("=== ") << "========== " << bc(Blue, Bold("Snakes & Ladders")) << " ===========" << Bold(" ===\n");
    // cout << tc(White, " _____________________________________________ \n");
    // cout << tc(White, "|") << tc(Blue ,"  __ __⁽⁸⁾    ") << tc(Green,"p1") << tc(Blue ," __⁽⁹⁾    __ __⁽¹⁰⁾   __ __⁽⁹⁹⁾ ") << tc(White, "|\n");
    // cout << tc(White, "|") << tc(Blue,"  __ __⁽⁷⁾    __ __⁽⁶⁾    ")<< tc(Red, "__ __⁻¹") << tc(Blue, "    __ __⁽⁴⁾   ") << tc(White, "|\n" );
    // cout << tc(White, "|") << tc(Blue , "  __ __⁽⁰⁾    __ __⁽¹⁾    ") << tc(Yellow,"p2") << tc(Blue ," __⁽²⁾    ")<< tc(Red, "__ __⁻¹  ") << tc(White, "|\n" );
    // cout << tc(White, " _____________________________________________ \n");

    cout << Get_File_Contents(R"(E:\Work_Space\Programing\C++\My_Tools\test.txt)");
    return 0;
}
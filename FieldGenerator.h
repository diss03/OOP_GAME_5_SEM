#pragma once
#include "Field.h"
//#include "Generator.h"
#include "EventCreator.h"
#include "Enums.h"

//template<class Rules1, class Rules2, class Rules3, class Rules4, class Rules5, class Rules6, class Rules7>
template<class ... Rules>
class FieldGenerator /*: public Generator*/
{
public:
    //FieldGenerator(Rules ...) = default;
    //FieldGenerator(Rules... rules);
    
    Field* generate(int height = 10, int width = 10, Player* player = nullptr, InfoLog* log_info = nullptr){
        Field* field = new Field(height, width, player, log_info);
        EventCreator ev_cr = EventCreator(field, player);
        field->InitCells();
        //(... , Rules(ev_cr));
        (Rules()(ev_cr), ...);
        //(Rules1()(ev_cr), Rules2()(ev_cr), Rules3()(ev_cr), Rules4()(ev_cr), Rules5()(ev_cr), Rules6()(ev_cr), Rules7()(ev_cr));
        return field;
    };
};


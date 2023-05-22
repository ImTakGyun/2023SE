#include "GetRecruitInfoList.hpp"
#include "RecruitInfo.hpp"
#include "GeneralMember.hpp"
#include "CompanyMember.hpp"
#include "Server.hpp"

// CompanyMember의 _ownedRecruitInfo를 불러와
// 차례대로 순회하며 showResult
void GetRecruitInfoList::run()
{
    Server* server = Server::getInstance();
    CompanyMember* member = dynamic_cast<CompanyMember*>(server->getCurMember());
    _getRecruitInfoListUI.startInterface();
    vector<RecruitInfo*> info = member->listRecruitInfo();
    for (int i = 0; i < info.size(); i++)
    {
        _getRecruitInfoListUI.showResult(info[i]->getRecruitInfoDetail());
    }
}

GetRecruitInfoList::GetRecruitInfoList() {}
GetRecruitInfoList::~GetRecruitInfoList() {}

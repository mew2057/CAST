/*******************************************************************************
 |    BBLV_Metadata.h
 |
 |  � Copyright IBM Corporation 2015,2016. All Rights Reserved
 |
 |    This program is licensed under the terms of the Eclipse Public License
 |    v1.0 as published by the Eclipse Foundation and available at
 |    http://www.eclipse.org/legal/epl-v10.html
 |
 |    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
 |    restricted by GSA ADP Schedule Contract with IBM Corp.
 *******************************************************************************/

#ifndef BB_BBLVMETADATA_H_
#define BB_BBLVMETADATA_H_

#include <map>
#include <vector>

#include "BBJob.h"
#include "BBLV_Info.h"
#include "BBTransferDef.h"
#include "LVKey.h"
#include "xfer.h"


/*******************************************************************************
 | Forward declarations
 *******************************************************************************/
class BBTagID;
class BBTagInfo;


/**
 * \class BBLV_Metadata
 * Defines the map of LVKey->BBLVInfo
 */
class BBLV_Metadata
{
  public:
    // Static methods
    static void appendAsyncRequestForStopTransfer(const string& pCN_HostName, const uint64_t pJobId, const uint64_t pJobStepId, const uint64_t pHandle, const uint32_t pContribId, const uint64_t pCancelScope);
    static int update_xbbServerAddData(txp::Msg* pMsg, const uint64_t pJobId);
    static int update_xbbServerRemoveData(const uint64_t pJobId);

    // Non-static methods
    void accumulateTotalLocalContributorInfo(const uint64_t pHandle, size_t& pTotalContributors, size_t& pTotalLocalReportingContributors);
    int addLVKey(const string& pHostName, txp::Msg* pMsg, const LVKey* pLVKey, const uint64_t pJobId, BBLV_Info& pLV_Info, const TOLERATE_ALREADY_EXISTS_OPTION pTolerateAlreadyExists);
    int attemptToUnconditionallyStopThisTransferDefinition(const string& pHostName, const string& pCN_HostName, const uint64_t pJobId, const uint64_t pJobStepId, const uint64_t pHandle, const uint32_t pContribId);
    int cleanLVKeyOnly(const LVKey* pLVKey);
    void cleanUpAll(const uint64_t pJobId);
    void dump(char* pSev, const char* pPrefix=0);
    void ensureStageOutEnded(const LVKey* pLVKey);
    int getAnyLVKeyForUuidAndJobId(LVKey* &pLVKeyOut, LVKey* &pLVKeyIn, const uint64_t pJobId);
    BBLV_Info* getAnyTagInfo2ForUuid(const LVKey* pLVKey) const;
    int getInfo(const std::string& pConnectionName, LVKey& pLVKey, BBLV_Info* &pLV_Info, BBTagInfo* &pTagInfo, BBTagID& pTagId, const BBJob pJob, vector<uint32_t>*& pContrib, const uint64_t pHandle, const uint32_t pContribId);
    BBLV_Info* getLV_Info(const LVKey* pLVKey) const;
    int getLVKey(const std::string& pConnectionName, LVKey* &pLVKey, const uint64_t pJobId, const uint32_t pContribId);
    int getLVKey(const std::string& pConnectionName, LVKey* &pLVKey, BBTagInfo* &pTagInfo, BBJob pJob, const uint64_t pTag, const uint64_t pNumContrib, const uint32_t pContrib[]);
    size_t getTotalTransferSize(const LVKey& pLVKey);
    int getTransferHandle(uint64_t& pHandle, const LVKey* pLVKey, const BBJob pJob, const uint64_t pTag, const uint64_t pNumContrib, const uint32_t pContrib[]);
    void getTransferHandles(vector<uint64_t>& pHandles, const BBJob pJob, const BBSTATUS pMatchStatus);
    int hasLVKey(const LVKey* pLVKey, const uint64_t pJobId);
    void removeAllLogicalVolumesForUuid(const string& pHostName, const LVKey* pLVKey, const uint64_t pJobId);
    void removeLVKey(const uint64_t pJobId, const LVKey* pLVKey);
    int retrieveTransfers(BBTransferDefs& pTransferDefs);
    void sendTransferCompleteForHandleMsg(const string& pHostName, const string& pCN_HostName, const uint64_t pHandle, const BBSTATUS pStatus=BBNONE);
    void setCanceled(const uint64_t pJobId, const uint64_t pJobStepId, const uint64_t pHandle, const int pRemoveOption);
    int setSuspended(const string& pHostName, const string& pCN_HostName, const int pValue);
    int stopTransfer(const string& pHostName, const string& pCN_HostName, const uint64_t pJobId, const uint64_t pJobStepId, const uint64_t pHandle, const uint32_t pContribId);
    int verifyJobIdExists(const std::string& pConnectionName, const LVKey* pLVKey, const uint64_t pJobId);

    map<LVKey, BBLV_Info> metaDataMap;
};

#endif /* BB_BBLVMETADATA_H_ */

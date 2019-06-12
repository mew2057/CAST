/*******************************************************************************
 |    bbserver.h
 |
 |  © Copyright IBM Corporation 2015,2016. All Rights Reserved
 |
 |    This program is licensed under the terms of the Eclipse Public License
 |    v1.0 as published by the Eclipse Foundation and available at
 |    http://www.eclipse.org/legal/epl-v10.html
 |
 |    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
 |    restricted by GSA ADP Schedule Contract with IBM Corp.
 *******************************************************************************/


/**
 * \file bbserver.h
 * This file is the burst buffer server header file.
 */

#ifndef BB_BBSERVER_H_
#define BB_BBSERVER_H_

#include "bbinternal.h"

/*******************************************************************************
 | Forward declarations
 *******************************************************************************/


extern void sendMsgAndWaitForNonDataReply(txp::Connex* pConnection, txp::Msg* &pMsg);

#endif /* BB_BBSERVER_H_ */

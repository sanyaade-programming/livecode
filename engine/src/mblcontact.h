/* Copyright (C) 2003-2013 Runtime Revolution Ltd.

This file is part of LiveCode.

LiveCode is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License v3 as published by the Free
Software Foundation.

LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

#ifndef __MOBILE_CONTACT__
#define __MOBILE_CONTACT__

#include "mblsyntax.h"

typedef enum
{
	kMCContactPropertyUnknown,
	kMCContactPropertyTitle,				// iOS
	kMCContactPropertyMessage,				// iOS
	kMCContactPropertyAlternateName,		// iOS, Android (autogenerated in Android)
	kMCContactPropertyFirstName,			// iOS, Android
	kMCContactPropertyLastName,				// iOS, Android
	kMCContactPropertyMiddleName,			// iOS, Android
	kMCContactPropertyPrefix,				// iOS, Android
	kMCContactPropertySuffix,				// iOS, Android
	kMCContactPropertyNickName,				// iOS
	kMCContactPropertyFirstNamePhonetic,	// iOS, Android
	kMCContactPropertyLastNamePhonetic,		// iOS, Android
	kMCContactPropertyMiddleNamePhonetic,	// iOS, Android
	kMCContactPropertyOrganization,			// iOS, Android
	kMCContactPropertyJobTitle,				// iOS
	kMCContactPropertyDepartment,			// iOS
	kMCContactPropertyNote,					// iOS, Android
	
	kMCContactPropertyEmail,				// iOS, Android
	kMCContactPropertyPhone,				// iOS, Android
	kMCContactPropertyAddress,				// iOS, Android
} MCContactEntryProperty;

typedef enum
{
	kMCContactLabelHome,		// iOS, Android
	kMCContactLabelWork,		// iOS, Android
	kMCContactLabelOther,		// iOS, Android
	
	kMCContactLabelMobile,		// iOS
	kMCContactLabeliPhone,		// iOS
	kMCContactLabelMain,		// iOS
	kMCContactLabelHomeFax,		// iOS
	kMCContactLabelWorkFax,		// iOS
	kMCContactLabelOtherFax,	// iOS
	kMCContactLabelPager,		// iOS
} MCContactEntryLabel;

typedef enum
{
	kMCContactKeyStreet,		// iOS, Android
	kMCContactKeyCity,			// iOS, Android
	kMCContactKeyState,			// iOS, Android
	kMCContactKeyZip,			// iOS, Android
	kMCContactKeyCountry,		// iOS, Android
	kMCContactKeyCountryCode,	// iOS
} MCContactEntryKey;

bool MCContactAddProperty(MCExecPoint &ep, MCVariableValue *p_contact, MCNameRef p_property, MCString p_value);
bool MCContactAddPropertyWithLabel(MCExecPoint &ep, MCVariableValue *p_contact, MCNameRef p_property, MCNameRef p_label, MCVariableValue *p_value);
bool MCContactAddPropertyWithLabel(MCExecPoint &ep, MCVariableValue *p_contact, MCNameRef p_property, MCNameRef p_label, MCString p_value);

bool MCParseParameters(MCParameter*& p_parameters, const char *p_format, ...);
bool MCSystemPickContact(int32_t& r_result);
bool MCSystemShowContact(int32_t p_contact_id, int32_t& r_result);
bool MCSystemCreateContact(int32_t& r_result);
bool MCSystemUpdateContact(MCVariableValue *p_contact, const char *p_title, const char *p_message, const char *p_alternate_name, int32_t &r_result);
bool MCSystemGetContactData(MCExecContext &r_ctxt, int32_t p_contact_id, MCVariableValue*& r_contact_data);
bool MCSystemRemoveContact(int32_t p_contact_id);
bool MCSystemAddContact(MCVariableValue *p_contact, int32_t &r_result);
bool MCSystemFindContact(const char* p_contact_name, char*& r_result);

#endif
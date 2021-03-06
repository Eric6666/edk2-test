/** @file

  Copyright 2006 - 2016 Unified EFI, Inc.<BR>
  Copyright (c) 2010 - 2016, Intel Corporation. All rights reserved.<BR>   

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at 
  http://opensource.org/licenses/bsd-license.php
 
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 
**/
/*++

Module Name:

  AcpiTableProtocol.h

Abstract:

  ACPI Table Protocol from the UEFI 2.1 specification.

  This protocol may be used to install or remove an ACPI table from a platform.

--*/

#ifndef _ACPI_TABLE_PROTOCOL_H_
#define _ACPI_TABLE_PROTOCOL_H_


//
// Global ID for the Acpi Table Protocol
//
#define EFI_ACPI_TABLE_PROTOCOL_GUID \
  { 0xffe06bdd, 0x6107, 0x46a6, {0x7b, 0xb2, 0x5a, 0x9c, 0x7e, 0xc5, 0x27, 0x5c }}

typedef struct _EFI_ACPI_TABLE_PROTOCOL EFI_ACPI_TABLE_PROTOCOL;
/*
typedef struct {
  UINT32  Signature;
  UINT32  Length;
  UINT8   Revision;
  UINT8   Checksum;
  UINT8   OemId[6];
  UINT64  OemTableId;
  UINT32  OemRevision;
  UINT32  CreatorId;
  UINT32  CreatorRevision;
} EFI_ACPI_DESCRIPTION_HEADER;
*/
typedef
EFI_STATUS
(EFIAPI *EFI_ACPI_TABLE_INSTALL_ACPI_TABLE) (
  IN EFI_ACPI_TABLE_PROTOCOL                    *This,
  IN VOID                                       *AcpiTableBuffer,
  IN UINTN                                      AcpiTableBufferSize,
  OUT UINTN                                     *TableKey
  )
/*++

  Routine Description:
    Installs an ACPI table into the RSDT/XSDT.

  Arguments:
    This                  - Protocol instance pointer.
    AcpiTableBuffer       - A pointer to a buffer containing the ACPI table to be installed.
    AcpiTableBufferSize   - Specifies the size, in bytes, of the AcpiTableBuffer buffer.
    TableKey              - Reurns a key to refer to the ACPI table.

  Returns:
    EFI_SUCCESS           - The table was successfully inserted.
    EFI_INVALID_PARAMETER - Either AcpiTableBuffer is NULL, TableKey is NULL, or AcpiTableBufferSize 
                            and the size field embedded in the ACPI table pointed to by AcpiTableBuffer
                            are not in sync.
    EFI_OUT_OF_RESOURCES  - Insufficient resources exist to complete the request.

--*/
;

typedef
EFI_STATUS
(EFIAPI *EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE) (
  IN EFI_ACPI_TABLE_PROTOCOL                    *This,
  IN UINTN                                      TableKey
  )
/*++

  Routine Description:
    Removes an ACPI table from the RSDT/XSDT.

  Arguments:
    This          - Protocol instance pointer.
    TableKey      - Specifies the table to uninstall.  The key was returned from InstallAcpiTable().

  Returns:
    EFI_SUCCESS   - The table was successfully uninstalled.
    EFI_NOT_FOUND - TableKey does not refer to a valid key for a table entry.

--*/
;

//
// Interface structure for the ACPI Table Protocol
//
struct _EFI_ACPI_TABLE_PROTOCOL {
  EFI_ACPI_TABLE_INSTALL_ACPI_TABLE    InstallAcpiTable;
  EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE  UninstallAcpiTable;
};

extern EFI_GUID gBlackBoxEfiAcpiTableProtocolGuid;

#endif

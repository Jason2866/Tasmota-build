# Matter Standard Namespaces

# Version 1.4.

```
Document: 23-31936-004_Matter-1.4.1-Standard-Namespaces.pdf
March 17, 2025
Sponsored by: Connectivity Standards Alliance
Accepted by: This document has been accepted for release by the Connectivity
Standards Alliance Board of Directors on March 17, 2025
Abstract: The Matter specification defines fundamental requirements to
enable an interoperable application layer solution for smart home
devices over the Internet Protocol.
Keywords: Referenced in Chapter 1.
```
Copyright © 2022-2025 Connectivity Standards Alliance, Inc.
508 Second Street, Suite 109B Davis, CA 95616 - USA
[http://www.csa-iot.org](http://www.csa-iot.org)
All rights reserved.

Permission is granted to members of the Connectivity Standards Alliance to reproduce this
document for their own use or the use of other Connectivity Standards Alliance members only,
provided this notice is included. All other rights reserved. Duplication for sale, or for commercial or
for-profit use is strictly prohibited without the prior written consent of the Connectivity Standards
Alliance.



# Matter Semantic Tag Namespaces

```
Version 1.4.1, 2025-03-12 06:42:16 -0700: Approved
```


## Table of Contents

## Revision History.  

- Notice of Use and Disclosure.  
- Revision History.  
- 1. Introduction.  
   - 1.1. CSA Reference Documents.  
- 2. Common Closure Semantic Tag Namespace.  
- 3. Common Compass Direction Semantic Tag Namespace.  
- 4. Common Compass Location Semantic Tag Namespace.  
- 5. Common Direction Semantic Tag Namespace.  
- 6. Common Level Semantic Tag Namespace.  
- 7. Common Location Semantic Tag Namespace.  
- 8. Common Number Semantic Tag Namespace.  
- 9. Common Position Semantic Tag Namespace.  
   - 9.1. Examples.  
- 10. Common Landmark Semantic Tag Namespace.  
- 11. Common Relative Position Semantic Tag Namespace.  
- 12. Electrical Measurement Semantic Tag Namespace.  
- 13. Common Area Semantic Tag Namespace.  
- 14. Laundry Semantic Tag Namespace.  
- 15. Power Source Semantic Tag Namespace.  
   - 15.1. Grid Tag.  
   - 15.2. Solar Tag.  
   - 15.3. Battery Tag.  
   - 15.4. EV Tag.  
- 16. Refrigerator Semantic Tag Namespace.  
- 17. Room Air Conditioner Semantic Tag Namespace.  
- 18. Switches Semantic Tag Namespace.  
   - 18.1. Custom Tag.  



**Notice of Use and Disclosure**

Copyright © Connectivity Standards Alliance (2023). All rights reserved. The information within this
document is the property of the Connectivity Standards Alliance and its use and disclosure are
restricted, except as expressly set forth herein.

Connectivity Standards Alliance hereby grants you a fully-paid, non-exclusive, nontransferable,
worldwide, limited and revocable license (without the right to sublicense), under Connectivity Stan­
dards Alliance’s applicable copyright rights, to view, download, save, reproduce and use the docu­
ment solely for your own internal purposes and in accordance with the terms of the license set
forth herein. This license does not authorize you to, and you expressly warrant that you shall not:
(a) permit others (outside your organization) to use this document; (b) post or publish this docu­
ment; (c) modify, adapt, translate, or otherwise change this document in any manner or create any
derivative work based on this document; (d) remove or modify any notice or label on this docu­
ment, including this Copyright Notice, License and Disclaimer. The Connectivity Standards Alliance
does not grant you any license hereunder other than as expressly stated herein.

Elements of this document may be subject to third party intellectual property rights, including
without limitation, patent, copyright or trademark rights, and any such third party may or may not
be a member of the Connectivity Standards Alliance. Connectivity Standards Alliance members
grant other Connectivity Standards Alliance members certain intellectual property rights as set
forth in the Connectivity Standards Alliance IPR Policy. Connectivity Standards Alliance members
do not grant you any rights under this license. The Connectivity Standards Alliance is not responsi­
ble for, and shall not be held responsible in any manner for, identifying or failing to identify any or
all such third party intellectual property rights. Please visit [http://www.csa-iot.org](http://www.csa-iot.org) for more information
on how to become a member of the Connectivity Standards Alliance.

This document and the information contained herein are provided on an “AS IS” basis and the Con­
nectivity Standards Alliance DISCLAIMS ALL WARRANTIES EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO (A) ANY WARRANTY THAT THE USE OF THE INFORMATION HEREIN WILL NOT
INFRINGE ANY RIGHTS OF THIRD PARTIES (INCLUDING WITHOUT LIMITATION ANY INTELLEC­
TUAL PROPERTY RIGHTS INCLUDING PATENT, COPYRIGHT OR TRADEMARK RIGHTS); OR (B) ANY
IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE OR
NONINFRINGEMENT. IN NO EVENT WILL THE CONNECTIVITY STANDARDS ALLIANCE BE LIABLE
FOR ANY LOSS OF PROFITS, LOSS OF BUSINESS, LOSS OF USE OF DATA, INTERRUPTION OF BUSI­
NESS, OR FOR ANY OTHER DIRECT, INDIRECT, SPECIAL OR EXEMPLARY, INCIDENTAL, PUNITIVE OR
CONSEQUENTIAL DAMAGES OF ANY KIND, IN CONTRACT OR IN TORT, IN CONNECTION WITH THIS
DOCUMENT OR THE INFORMATION CONTAINED HEREIN, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH LOSS OR DAMAGE.

All company, brand and product names in this document may be trademarks that are the sole prop­
erty of their respective owners.

This notice and disclaimer must be included on all copies of this document.

Connectivity Standards Alliance
508 Second Street, Suite 206
Davis, CA 95616, USA

```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 1
```

Page 2 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Revision History**

```
Revision Date Details Editor
1 October 18, 2023 Version 1.2 Robert Szewczyk
2 April 17, 2024 Version 1.3 Robert Szewczyk
3 November 4, 2024 Version 1.4 Robert Szewczyk
4 March 17, 2024 Version 1.4.1 Robert Szewczyk
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 3
```

Page 4 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 1. Introduction**

This document contains namespaces as part of the semantic tag feature.

The standard namespaces are defined in this appendix. They consist of the common namespaces
and device-specific namespaces.

The Common namespaces start with Namespace ID 0x01 and contains semantic tags that can apply
to any domain. Examples include direction words like 'left', 'right', 'up' and 'down' or location words
like 'inside' and 'outside'.

Device-specific namespaces begin with Namespace ID 0x41. The semantic tags defined in the
device-specific namespaces SHALL be restricted for use within each device type or set of device
types.

### NOTE

```
Some namespaces specific to certain group of device types (related to Energy and
Laundry) have been assigned an ID from the common range, even though they are
only applicable to a certain set of device types only.
```
A TagList MAY combine several of these tags, as appropriate for the device, provided that for any
given device type the tags come from the namespace for that device type as well as any of the com­
mon namespaces, and/or from a manufacturer-specific namespace. Example: An outdoor luminaire
with two light units, one shining upwards and one shining downwards. One light unit would be
represented by an endpoint with a TagList which has TagStructs with Tags "Location.Outdoor" and
"Position.Top" and "Direction.Upward", while the other light unit would be represented by an end­
point with a TagList which has TagStructs with Tags "Location.Outdoor" and "Position.Bottom" and
"Direction.Downward".

```
ID Namespace Summary
Common namespaces
0x01 Common Closure Namespace Tags which are useful in
describing things related to
closing and opening
0x02 Common Compass Direction
Namespace
```
```
Tags which are useful in
describing things related to
compass direction
0x03 Common Compass Location
Namespace
```
```
Tags which are useful in
describing things related to
compass location
0x04 Common Direction Namespace Tags which are useful in
describing things related to
direction
0x05 Common Level Namespace Tags which are useful in
describing things related to
level
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 5
```

```
ID Namespace Summary
0x06 Common Location Namespace Tags which are useful in
describing things related to
location
0x07 Common Number Namespace Tags which are useful in
describing things related to
numbering
0x08 Common Position Namespace Tags which are useful in
describing things related to
position
0x0A Electrical Measurement Name­
space
```
```
Tags which are useful in
describing electrical loads
0x0E Laundry Namespace Tags which are useful with
laundry device types
0x0F Power Source Namespace Tags which are useful with
power source device types
0x10 Common Area Namespace Tags which are useful in
describing things related to
home areas
0x11 Common Landmark Namespace Tags which are useful in
describing things related to
home landmarks
0x12 Common Relative Position
Namespace
```
```
Tags which are useful in
describing things related to
position relative to a reference
external to the device
Device-specific namespaces
0x41 Refrigerator Namespace Tags which are useful with
refrigeration device types
0x42 Room Air Conditioner Name­
space
```
```
Tags which are useful with
Room Air Conditioner device
types
0x43 Switches Namespace Tags which are useful with
switch device types
```
**1.1. CSA Reference Documents**

```
Reference Reference Location/URL Description
[CoreSpec] https://groups.csa-iot.org/wg/
members-all/document/
```
```
Core Matter Specification
```
```
Page 6 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.
```

**Reference Reference Location/URL Description**
[DeviceLibrary] https://groups.csa-iot.org/wg/
members-all/document/

```
Device Library
```
[AppClusters] https://groups.csa-iot.org/wg/
members-all/document/

```
Application Clusters
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 7
```

Page 8 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 2. Common Closure Semantic Tag**

**Namespace**

This section contains the Common Closure semantic tag namespace as part of the semantic tag fea­
ture.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a feature of a Closure, e.g. the button to activate opening a garage door.

```
ID Namespace
0x01 Common Closure
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Opening Move toward open position
0x01 Closing Move toward closed position
0x02 Stop Stop any movement
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 9
```

Page 10 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 3. Common Compass Direction**

**Semantic Tag Namespace**

This section contains the Common Compass Direction semantic tag namespace as part of the
semantic tag feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a movement into a certain compass direction. Note the difference with Chapter 4, _Com­_

## 4. Common Compass Location Semantic Tag Namespace.  

```
ID Namespace
0x02 Common Compass Direction
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Northward
0x01 North-Eastward
0x02 Eastward
0x03 South-Eastward
0x04 Southward
0x05 South-Westward
0x06 Westward
0x07 North-Westward
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 11
```

Page 12 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 4. Common Compass Location**

**Semantic Tag Namespace**

This section contains the Common Compass Location semantic tag namespace as part of the seman­
tic tag feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a position in a certain compass direction (e.g. an outdoor sensor in the North garden).
Note the difference with Chapter 3, _Common Compass Direction Semantic Tag Namespace_.

```
ID Namespace
0x03 Common Compass Location
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 North
0x01 North-East
0x02 East
0x03 South-East
0x04 South
0x05 South-West
0x06 West
0x07 North-West
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 13
```

Page 14 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 5. Common Direction Semantic Tag**

**Namespace**

This section contains the Common Direction semantic tag namespace as part of the semantic tag
feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a movement in a certain direction relative to the device. Note the difference with Chapter

## 9. Common Position Semantic Tag Namespace.  

```
ID Namespace
0x04 Common Direction
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Upward
0x01 Downward
0x02 Leftward
0x03 Rightward
0x04 Forward
0x05 Backward
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 15
```

Page 16 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 6. Common Level Semantic Tag**

**Namespace**

This section contains the Common Level semantic tag namespace as part of the semantic tag fea­
ture.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a certain level for a feature of a device (e.g. a button to set the speed of a fan).

```
ID Namespace
0x05 Common Level
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Low
0x01 Medium
0x02 High
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 17
```

Page 18 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 7. Common Location Semantic Tag**

**Namespace**

This section contains the Common Location semantic tag namespace as part of the semantic tag fea­
ture.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a location of a device (e.g. an outdoor temperature sensor).

```
ID Namespace
0x06 Common Location
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Indoor Element is indoors or related to
indoor equipment/conditions
(e.g. the "indoor" temperature).
0x01 Outdoor Element is outdoors or related
to outdoor equipment/condi­
tions (e.g. the "outdoor" temper­
ature).
0x02 Inside Element is located inside the
equipment (e.g. a sensor
"inside" a cabinet).
0x03 Outside Element is located outside the
equipment (e.g. a sensor "out­
side" a cabinet)
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 19
```

Page 20 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 8. Common Number Semantic Tag**

**Namespace**

This section contains the Common Number semantic tag namespace as part of the semantic tag fea­
ture.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a certain numeric feature of a device (e.g. a numeric input button).

```
ID Namespace
0x07 Common Number
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Zero
0x01 One
0x02 Two
0x03 Three
0x04 Four
0x05 Five
0x06 Six
0x07 Seven
0x08 Eight
0x09 Nine
0x0A Ten
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 21
```

Page 22 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 9. Common Position Semantic Tag**

**Namespace**

This section contains the Common Position semantic tag namespace as part of the semantic tag fea­
ture.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a position relative to the device (e.g. the temperature sensor in the top drawer of a refrig­
erator, or location of the buttons on a multi-button switch device). Note the difference with Chapter

## 3. Common Compass Direction Semantic Tag Namespace.  

```
ID Namespace
0x08 Common Position
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Left
0x01 Right
0x02 Top
0x03 Bottom
0x04 Middle
0x05 Row Numeric value provided in
Label field
0x06 Column Numeric value provided in
Label field
```
When multiple endpoints are used for device types, and the associated consumer-facing locations
of those endpoints are organized in a straight line, grid or matrix, these endpoints SHOULD be allo­
cated in top-to-bottom, left-to-right order.

For grids or arrays larger than 3 elements in any direction, the Row and Column tags SHOULD be
used.

If the Row or Column tags are used, the Label field in the same Semantic Tag structure SHALL be
filled with a number comprised of Arabic numerals encoded as a string to indicate the row/column
of the item. Number words (e.g. "one", "two", etc.) SHALL NOT be used to describe the position of
the item. The first row/column SHALL use Label "1".

**9.1. Examples**

```
The following example illustrates a composed device comprised of 9 endpoints arranged in a
3x3 grid. This example uses position tags to indicate position.
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 23
```

```
Composed device arranged in a 3x3 grid
Top Left Top Middle Top Right
Middle Left Middle Middle Right
Bottom Left Bottom Middle Bottom Right
```
```
The endpoints would be populated in this order (showing the TagList in their Descriptor clus­
ter):
```
- EP 21: Top Left
- EP 22: Top Middle
- EP 23: Top Right
- EP 24: Middle Left
- EP 25: Middle
- EP 26: Middle Right
- EP 27: Bottom Left
- EP 28: Bottom Middle
- EP 29: Bottom Right

```
The following example illustrates a composed device comprised of 8 endpoints arranged in a
2x4 grid. This example uses the Row and Column tags along with Arabic numeral Labels to
indicate position.
Row "1" Column "1" Row "1" Column "2" Row "1" Column "3" Row "1" Column "4"
Row "2" Column "1" Row "2" Column "2" Row "2" Column "3" Row "2" Column "4"
The endpoints would be populated in this order (showing the TagList in their Descriptor clus­
ter):
```
- EP 31: {Row, "1"}, {Column, "1"}
- EP 32: {Row, "1"}, {Column, "2"}
- EP 33: {Row, "1"}, {Column, "3"}
- EP 34: {Row, "1"}, {Column, "4"}
- EP 35: {Row, "2"}, {Column, "1"}
- EP 36: {Row, "2"}, {Column, "2"}
- EP 37: {Row, "2"}, {Column, "3"}
- EP 38: {Row, "2"}, {Column, "4"}

Page 24 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 10. Common Landmark Semantic**

**Tag Namespace**

This section contains the Common Landmark semantic tag namespace as part of the semantic tag
feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a home landmark.

```
ID Namespace
0x11 Common Landmark Namespace
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Air Conditioner
0x01 Air Purifier
0x02 Back Door
0x03 Bar Stool
0x04 Bath Mat
0x05 Bathtub
0x06 Bed
0x07 Bookshelf
0x08 Chair
0x09 Christmas Tree
0x0A Coat Rack
0x0B Coffee Table
0x0C Cooking Range
0x0D Couch
0x0E Countertop
0x0F Cradle
0x10 Crib
0x11 Desk
0x12 Dining Table
0x13 Dishwasher
0x14 Door
0x15 Dresser
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 25
```

```
ID Name Summary
0x16 Laundry Dryer
0x17 Fan
0x18 Fireplace
0x19 Freezer
0x1A Front Door
0x1B High Chair
0x1C Kitchen Island
0x1D Lamp
0x1E Litter Box
0x1F Mirror
0x20 Nightstand
0x21 Oven
0x22 Pet Bed
0x23 Pet Bowl
0x24 Pet Crate
0x25 Refrigerator
0x26 Scratching Post
0x27 Shoe Rack
0x28 Shower
0x29 Side Door
0x2A Sink
0x2B Sofa
0x2C Stove
0x2D Table
0x2E Toilet
0x2F Trash Can
0x30 Laundry Washer
0x31 Window
0x32 Wine Cooler
```
Page 26 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 11. Common Relative Position**

**Semantic Tag Namespace**

This section contains the Common Relative Position semantic tag namespace as part of the semantic
tag feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with a position relative to some reference, which must be specified by the user of these tags.
For example, the position may be relative to a household item, such as a dining table, and the user
of these tags must indicate that. Note the difference with Chapter 9, _Common Position Semantic Tag
Namespace_ , which contains tags indicating the position relative to the device.

```
ID Namespace
0x12 Common Relative Position
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Under
0x01 Next To Area in proximity to the point
of reference
0x02 Around The area surrounding the point
the reference
0x03 On
0x04 Above
0x05 Front Of
0x06 Behind
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 27
```

Page 28 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 12. Electrical Measurement**

**Semantic Tag Namespace**

This section contains the standard semantic tag namespace for electrical measurement as part of
the semantic tag feature.

The tags contained in this namespace are restricted for use in the electrical measurement domain
and SHALL NOT be used in any other domain or context.

```
ID Namespace
0x0A Electrical Measurement
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 DC Indicates values measured for a
DC load
0x01 AC Indicates values measured for a
single-phase AC load, or values
measured for the collective load
on a polyphase AC power sup­
ply
0x02 ACPhase1 Indicates values measured for
an AC load on phase 1 of a
polyphase power supply
0x03 ACPhase2 Indicates values measured for
an AC load on phase 2 of a
polyphase power supply
0x04 ACPhase3 Indicates values measured for
an AC load on phase 3 of a
polyphase power supply
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 29
```

Page 30 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 13. Common Area Semantic Tag**

**Namespace**

This section contains the Common Area semantic tag namespace as part of the semantic tag feature.

The tags contained in this namespace MAY be used in any domain or context, to indicate an associa­
tion with an indoor or outdoor area of a home.

```
ID Namespace
0x10 Common Area Namespace
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Aisle
0x01 Attic
0x02 Back Door
0x03 Back Yard
0x04 Balcony
0x05 Ballroom
0x06 Bathroom Also known as Restroom
0x07 Bedroom
0x08 Border
0x09 Boxroom A small room typically used for
storage
0x0A Breakfast Room
0x0B Carport
0x0C Cellar
0x0D Cloakroom
0x0E Closet
0x0F Conservatory
0x10 Corridor
0x11 Craft Room
0x12 Cupboard
0x13 Deck
0x14 Den A small, comfortable room for
individual activities such as
work or hobbies
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 31
```

```
ID Name Summary
0x15 Dining
0x16 Drawing Room
0x17 Dressing Room
0x18 Driveway
0x19 Elevator
0x1A Ensuite A bathroom directly accessible
from a bedroom
0x1B Entrance
0x1C Entryway
0x1D Family Room
0x1E Foyer
0x1F Front Door
0x20 Front Yard
0x21 Game Room
0x22 Garage
0x23 Garage Door
0x24 Garden
0x25 Garden Door
0x26 Guest Bathroom Also known as Guest Restroom
0x27 Guest Bedroom
0x28 Guest Room
0x29 Gym
0x2A Hallway
0x2B Hearth Room A cozy room containing a fire­
place or other point heat source
0x2C Kids Room
0x2D Kids Bedroom
0x2E Kitchen
0x2F Laundry Room
0x30 Lawn
0x31 Library
0x32 Living Room
0x33 Lounge
0x34 Media/TV Room
```
Page 32 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**ID Name Summary**
0x35 Mud Room A space used to remove soiled
garments prior to entering the
domicile proper
0x36 Music Room
0x37 Nursery
0x38 Office
0x39 Outdoor Kitchen
0x3A Outside
0x3B Pantry AKA a larder, a place where
food is stored
0x3C Parking Lot
0x3D Parlor
0x3E Patio
0x3F Play Room
0x40 Pool Room
0x41 Porch
0x42 Primary Bathroom
0x43 Primary Bedroom
0x44 Ramp
0x45 Reception Room
0x46 Recreation Room
0x47 Roof
0x48 Sauna
0x49 Scullery A utility space for cleaning
dishes and laundry
0x4A Sewing Room
0x4B Shed
0x4C Side Door
0x4D Side Yard
0x4E Sitting Room
0x4F Snug An informal space meant to be
'cozy', 'snug', relaxed, meant to
share with family or friends
0x50 Spa
0x51 Staircase

```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 33
```

```
ID Name Summary
0x52 Steam Room
0x53 Storage Room
0x54 Studio
0x55 Study
0x56 Sun Room
0x57 Swimming Pool
0x58 Terrace
0x59 Toilet A room dedicated to a toilet; a
water closet / WC
0x5A Utility Room
0x5B Ward
0x5C Workshop
```
Page 34 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 14. Laundry Semantic Tag**

**Namespace**

This section contains the standard semantic tag namespace for laundry as part of the semantic tag
feature.

The tags contained in this namespace are restricted for use in the laundry domain and SHALL NOT
be used in any other domain or context.

```
ID Namespace
0x0E Laundry
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Normal
0x01 Light Dry
0x02 Extra Dry
0x03 No Dry
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 35
```

Page 36 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 15. Power Source Semantic Tag**

**Namespace**

This section contains the standard semantic tag namespace for power sources as part of the seman­
tic tag feature.

The tags contained in this namespace are restricted for use in the power source domain and SHALL
NOT be used in any other domain or context.

```
ID Namespace
0x0F Power Source
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Unknown The Power Source cluster is
related to power provided from
an unknown source
0x01 Grid The Power Source cluster is
related to power provided from
the electrical grid
0x02 Solar The Power Source cluster is
related to power provided from
a solar panel array
0x03 Battery The Power Source cluster is
related to power provided from
a battery
0x04 EV The Power Source cluster is
related to power provided from
an electric vehicle
```
**15.1. Grid Tag**

Power Source clusters with this tag SHALL implement the WIRED feature.

**15.2. Solar Tag**

Power Source clusters with this tag SHALL implement the WIRED feature.

**15.3. Battery Tag**

Power Source clusters with this tag SHALL implement the BAT feature.

```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 37
```

**15.4. EV Tag**

Power Source clusters with this tag SHALL implement the BAT feature.

```
Page 38 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.
```

**Chapter 16. Refrigerator Semantic Tag**

**Namespace**

This section contains the standard semantic tag namespace for refrigerators as part of the semantic
tag feature.

The tags contained in this namespace are restricted for use in the refrigerator domain and SHALL
NOT be used in any other domain or context.

```
ID Namespace
0x41 Refrigerator
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Refrigerator
0x01 Freezer
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 39
```

Page 40 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 17. Room Air Conditioner Semantic**

**Tag Namespace**

This section contains the standard semantic tag namespace for room air conditioners as part of the
semantic tag feature.

The tags contained in this namespace are restricted for use in the room air conditioner domain and
SHALL NOT be used in any other domain or context.

```
ID Namespace
0x42 Room Air Conditioner
```
The following tags are defined in this namespace.

```
ID Name Summary
0x00 Evaporator
0x01 Condenser
```
```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 41
```

Page 42 Copyright © Connectivity Standards Alliance, Inc. All rights reserved.


**Chapter 18. Switches Semantic Tag**

**Namespace**

This section contains the standard semantic tag namespace for switches as part of the semantic tag
feature.

The tags contained in this namespace are restricted for use in the switches domain and SHALL NOT
be used in any other domain or context. They are intended to indicate the function of a button on a
switch device to allow a client to make an optimized user interface which matches the actual device
without requiring a-priori knowledge of the layout of each specific switch device.

Please see the rules for applying these and other tags for switch devices, e.g. from the Common
Position Namespace and the Common Number Namespace in the Generic Switch device type sec­
tion in the Device Library.

```
ID Namespace
0x43 Switches
```
The following tags are defined in this namespace.

```
ID Name Summary
tags to identify intended function of a button
0x00 On
0x01 Off
0x02 Toggle
0x03 Up e.g. dim up (light)
0x04 Down e.g. dim down (light)
0x05 Next e.g. select next scene
0x06 Previous e.g. select previous scene
0x07 Enter/OK/Select
0x08 Custom Textual description provided in
Label field
```
**18.1. Custom Tag**

When this value is used, the Label field in the same Semantic Tag structure SHALL be filled with a
textual description of the function indicated on the button, such as a label or icon printed on the
button, e.g. "dining".

```
Copyright © Connectivity Standards Alliance, Inc. All rights reserved. Page 43
```


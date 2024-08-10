/*
 * charlie_die.h
 *
 *  Created on: Aug 8, 2023
 *      Author: user
 */

#ifndef INC_CHARLIE_DIE_H_
#define INC_CHARLIE_DIE_H_

#define POV_DELAY 1

uint8_t RawRandomTo6FaceDie(uint32_t raw_random_value);
void AddToDieStats(uint32_t *die_face_stats, uint8_t die_face);

void LedsOff(void);

void Led0On(void);
void Led1On(void);
void Led2On(void);
void Led3On(void);
void Led4On(void);
void Led5On(void);

void DisplayDieFace1(void);
void DisplayDieFace2(void);
void DisplayDieFace3(void);
void DisplayDieFace4(void);
void DisplayDieFace5(void);
void DisplayDieFace6(void);

#endif /* INC_CHARLIE_DIE_H_ */

//==============================================================================
/**
 * @file	poke_anm_b015_1.s
 * @brief	�ːi
 * @author	
 * @date	
 *
 */
//==============================================================================

	.text
	
	.include	"past.h"
	.include	"past_def.h"
	
	.global		PAST_ANIME_B015_1
	
// =============================================================================
//
//
//	�w��	�ːi1
//
//
// =============================================================================
#define MOVE_WIDTH	(12)
#define START_SPD	(4)
#define BACK_SPD	(-2)
#define ADD_SPD		(1)
#define SHAKE_WIDTH	(4)
#define SHAKE_NUM	(15)
PAST_ANIME_B015_1:
	//���
	CALL_MF_LINE_DST		APPLY_SET,0,TARGET_DX,BACK_SPD,0,-MOVE_WIDTH
	HOLD_CMD
	//�ːi
	CALL_MF_LINE_DST		APPLY_ADD,0,TARGET_DX,START_SPD,ADD_SPD,MOVE_WIDTH
	HOLD_CMD

	SET_ADD_PARAM	PARAM_DX,USE_VAL,MOVE_WIDTH,PARAM_SET
	APPLY_TRANS
	
	//�U��
	SET_WORK_VAL		WORK0,SHAKE_WIDTH		//�U����
	START_LOOP		SHAKE_NUM
		SET_ADD_PARAM	PARAM_DX,USE_WORK,WORK0,PARAM_ADD
		APPLY_TRANS
		MUL_WORK_VAL	WORK0,CALC_VAL,WORK0,-1
		//�`�惊�N�G�X�g
		SET_REQUEST
	END_LOOP

	//���
	SET_ADD_PARAM	PARAM_DX,USE_VAL,MOVE_WIDTH,PARAM_SET
	APPLY_TRANS
	CALL_MF_LINE_DST		APPLY_ADD,0,TARGET_DX,BACK_SPD,0,0
	HOLD_CMD

	END_ANM

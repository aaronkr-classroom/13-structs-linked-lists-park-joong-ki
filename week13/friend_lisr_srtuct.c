#include <stdio.h>

#define MAX_COUNT 5 //친구 등록 가능한 최대 수

typedef char NAME_TYPE[14]; //13자까지 +NULL 문자
typedef unsigned short int US;
typedef struct {
	NAME_TYPE name;
	US age;
	float height;
	float weight;

}Person;

int AddFriend(Person *p_friend, int count) {
	// 입력 가능한 최대 수를 넘어쓴지 체크 함
	if (count < MAX_COUNT) {
		// friend
		p_friend = p_friend + count;
		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1.이름:");
		scanf_s("%s", p_friend->name , sizeof(p_friend->name));

		printf("2.나이:");
		scanf_s("%hu", &p_friend-> age); //age 배열의 count 위치에 나이를 저장함

		printf("2.키:");
		scanf_s("%f", &p_friend->height);

		printf("2.몸무게:");
		scanf_s("%f", p_friend->weight);

		printf("입력을 완료했습니다.\n\n");
		return 1;
	}
	else { // 입력 가능한 최대 수를 넘었을 때 오류를 출력함
		printf("최대 인원을 초과하여 입력을 할 수 없습니다.\n");
		printf("최대 %d명까지만 관리 가능합니다.\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriendList(Person *p_friend, int count) {
	if (count > 0) {
		printf("\n등록된 친구 목록\n");
		printf("============================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s,%3d,%6.2f,%6.2f\n", p_friend->name, p_friend->age, p_friend->height, p_friend->weight);
			p_friend++;
		}
		printf("============================\n");
	}
	else { //등록된 친구가 없으면 오류를 출력함
		printf("\n등록된 친구가 없습니다.\n\n");
	}
}

int main(void) {
	Person friends[MAX_COUNT];
	int count = 0, menu_num;

	//무한 루프: 사용자가 3을 누르면 break 문으로 종료시킴
	while (1) {
		// 매뉴를 화면에 출력함
		printf("\t[ 메뉴 ]\t\n");
		printf("============================\n");
		printf("1. 친구 추가\n");
		printf("2. 친구 목록 보기\n");
		printf("3. 종료\n");
		printf("============================\n");
		printf("번호 선택: \n");
		scanf_s("%d", &menu_num);

		if (menu_num == 3) break;

		switch (menu_num) {
		case 1:
			/*
			AddFriend 함수가 1을 반환하면 정상적으로 친구 정보가 추가된 것입니다.
			따라서 1을 반환 했을 때만 등록된 친구 수를 증가 시킵니다.
			*/
			if (AddFriend(friends, count))
				count++;
			break;
		case 2:
			ShowFriendList(friends, count);
			break;
		default:
			printf("1~3 번호만 선택할수 있습니다!!\n\n");
		}
	}

	return 0;
}
class TerranUnit:
    # 클래스 변수
    all_units = []

    def __init__(self, name, health, attack_power):
        self.name = name
        self.health = health
        self.attack_power = attack_power
        TerranUnit.all_units.append(self)

    def attack(self, target):
        print(f"{self.name}(이)가 {target}을(를) 공격합니다. 공격력은 {self.attack_power}입니다.")

    @classmethod
    def unit_count(cls):
        return len(cls.all_units)

    @classmethod
    def show_units(cls):
        for unit in cls.all_units:
            print(f"유닛 이름: {unit.name}, 체력: {unit.health}, 공격력: {unit.attack_power}")

class Marine(TerranUnit):
    def __init__(self, name):
        super().__init__(name, health=50, attack_power=6)

    def stimpack(self):
        if self.health > 10:
            self.health -= 10
            self.attack_power += 10
            print(f"{self.name}이(가) 스팀팩을 사용했습니다. 체력 10 감소, 공격력 10 증가")
        else:
            print(f"{self.name}의 체력이 부족하여 스팀팩을 사용할 수 없습니다.")

class Firebat(TerranUnit):
    def __init__(self, name):
        super().__init__(name, health=100, attack_power=8)

    def flame_thrower(self, target):
        print(f"{self.name}(이)가 {target}에 화염방사기를 사용합니다. 공격력은 {self.attack_power}입니다.")


if __name__ == "__main__":
    # 유닛 생성 및 테스트
    marine1 = Marine("마린1")
    marine2 = Marine("마린2")
    firebat1 = Firebat("파이어뱃1")

    marine1.attack("적 유닛")
    marine2.stimpack()
    firebat1.flame_thrower("적 유닛")

    # 전체 유닛과 유닛 수 출력
    TerranUnit.show_units()
    print(f"총 유닛 수: {TerranUnit.unit_count()}")

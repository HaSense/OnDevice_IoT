import sqlite3

# 데이터베이스 연결 (없으면 새로 생성)
conn = sqlite3.connect('address_book.db')
c = conn.cursor()

# 연락처 테이블 생성
c.execute('''CREATE TABLE IF NOT EXISTS contacts
             (id INTEGER PRIMARY KEY, name TEXT, phone TEXT, email TEXT, address TEXT)''')

def add_contact():
    name = input("이름: ")
    phone = input("전화번호: ")
    email = input("이메일: ")
    address = input("주소: ")
    
    c.execute("INSERT INTO contacts (name, phone, email, address) VALUES (?, ?, ?, ?)",
              (name, phone, email, address))
    conn.commit()
    print("연락처가 추가되었습니다.")

def view_contacts():
    c.execute("SELECT * FROM contacts")
    for row in c.fetchall():
        print(f"id: {row[0]}, 이름: {row[1]}, 전화번호: {row[2]}, 이메일: {row[3]}, 주소: {row[4]}")

def update_contact():
    contact_id = input("수정할 연락처 ID: ")
    name = input("새 이름: ")
    phone = input("새 전화번호: ")
    email = input("새 이메일: ")
    address = input("새 주소: ")
    
    c.execute("UPDATE contacts SET name = ?, phone = ?, email = ?, address = ? WHERE id = ?",
              (name, phone, email, address, contact_id))
    conn.commit()
    print("연락처가 수정되었습니다.")

def delete_contact():
    contact_id = input("삭제할 연락처 ID: ")
    c.execute("DELETE FROM contacts WHERE id = ?", (contact_id,))
    conn.commit()
    print("연락처가 삭제되었습니다.")

def main():
    while True:
        print("\n주소록")
        print("1. 연락처 추가")
        print("2. 연락처 조회")
        print("3. 연락처 수정")
        print("4. 연락처 삭제")
        print("5. 종료")
        choice = input("선택: ")
        
        if choice == "1":
            add_contact()
        elif choice == "2":
            view_contacts()
        elif choice == "3":
            update_contact()
        elif choice == "4":
            delete_contact()
        elif choice == "5":
            print("프로그램을 종료합니다.")
            break
        else:
            print("잘못된 선택입니다. 다시 시도하세요.")

if __name__ == "__main__":
    main()

# 데이터베이스 연결 종료
conn.close()

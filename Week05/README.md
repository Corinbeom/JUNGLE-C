# DataStructure 시험

- 일주일동안 만들었던 데이터스트럭쳐 파일 중 리뷰 받고 싶은 파일 1개만 제출하고 PR 생성
- 리뷰어 배정에 따라 다른 사람의 code를 GitHub의 PR 기능을 이용하여 review

## 시험 전 코드 제출 절차

0. 시험 내용 받아오기: C 개발 환경에서 Week05-08 project clone
    ```sh
    $ git clone https://github.com/krafton-jungle/KJ-W05-08-<기수>-<교육장번호>.git
    ```
1. 답안 작성을 위한 준비: 제출자 전용 dir과 branch 생성
    ```sh
    cd KJ-W05-08-<기수>-<교육장번호>/Week05                # Week05 dir로 이동
    mkdir ${제출자ID}                      # 제출자 전용 dir 생성
    cd ${제출자ID}
    cp ../sample_user/Makefile .           # sample Makefile 복사
    git checkout -b Week05/${제출자ID}     # 제출자 전용 branch 생성
    git push -u origin Week05/${제출자ID}  # git push를 위한 사전 작업
    ```
2. 코드 제출: `Week05/${제출자ID}/${리뷰받고싶은 c파일}` 복사
3. 리뷰어를 위한 준비: Pull request
    - https://github.com/krafton-jungle/KJ-W05-08-<기수>-<교육장번호> 에서 내 branch로 제대로 제출 되었는지 확인
    - `base:main <- compare:Week05/${제출자ID}` 방향으로 pull request 생성
    - Pull request 제목에 제출자의 이름을 포함하여 reviewer가 찾기 쉽도록 함
    - comment에 구현 특징 및 특기사항 (예: 어떤 case에서 실패함)을 적어
      reviewer가 이해하기 쉽도록 함

## 시험 절차
1. 지정된 리뷰어가 해당 코드를 리뷰
    - GitHub PR (pull request) 기능을 사용하여 line별/전체 review 작성
    - `git fetch --all` 후 `git checkout ${대상 branch}`명령을 통해 제출된 code를 직접 확인할 수 있음
2. 리뷰가 완료되면 'submit review' 버튼을 눌러 리뷰가 완료되었음을 알림
3. 리뷰 받은 코드 주인은 동료 피드백 설문 작성 시 해당 review에 대한 내용을 작성

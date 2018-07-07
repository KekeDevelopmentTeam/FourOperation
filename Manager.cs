using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Manager : MonoBehaviour {

    public GameObject questionPrefab;
    public Dictionary<int, int> qustion_answer;
    public List<GameObject> questions;
    public int count;
    public static Manager instance;
    public string str;
    public float time = 100f;
    public GameObject txtScore;
    public GameObject txtTime;
    private void Awake()
    {
        instance = this;
    }
    void Start () {
        txtScore = GameObject.Find("txtScore");
        txtTime = GameObject.Find("txtTime");
        CreateQuestion();
	}
    public void CreateQuestion()
    {
          float y = -92f;
        for (int i = 0; i < count; i++)
        {
            int n = Random.Range(20, 1000);
            int m = Random.Range(2, 5);

            GameObject question = GameObject.Instantiate(questionPrefab, new Vector3(1000f, y, 0f), Quaternion.identity, GameObject.Find("doPanel").transform);
            if (i % 2 == 0)
            {
                question.transform.localPosition = new Vector3(60f, y, 0);
            }

            else
            {
                question.transform.localPosition = new Vector3(580f, y, 0);
                y -= 40;
            }



            question.transform.Find("Equation").GetComponent<Text>().text = MakeString(n, m) + "=";
            question.GetComponent<QuestionBehavoir>().ans = n;
            question.transform.Find("correctAnswer").GetComponent<Text>().text = "正确答案：" + n.ToString();
            question.transform.Find("correctAnswer").gameObject.SetActive(false);
            questions.Add(question);
        }
    }
    public void Init()
    {
        int i = 1;
        float y = 92f;
        foreach(var e in questions)
        {
            GameObject.Instantiate(e, GameObject.Find("doPanel").transform);
            if (i % 2 == 1)
                e.transform.position.Set(85f, y,0);
            else
            {
                e.transform.position.Set(588f, y, 0);
                y -= 40f;
            }
        }
    }

    public string MakeString(int ans,int n)
    {
        if(n==1||ans==1)
        {
            return ans.ToString();
        }
        int randNum = Random.Range(0, 100);
        if (randNum < 25)
        {
            int left = Random.Range(1, ans);
            int right = ans - left;
            if (Random.Range(0, 2) < 1)
            {
                return left.ToString() +"+"+ MakeString(right, n - 1);
            }
            else
            {
                return MakeString(left, n - 1) +"+"+ right.ToString();
            }


        }
        else if (randNum >= 25 && randNum < 50)
        {
            int left = Random.Range(ans, 100);
            int right = left - ans;
            if (Random.Range(0, 2) < 1)
            {
                return left.ToString() +"-"+ MakeString(right, n - 1);
            }
            else
            {
                return MakeString(left, n - 1) +"-"+ right.ToString();
            }
        }
        else if (randNum >= 50 && randNum < 75)
        {
            int left;
            for (left = 1; left < ans; left++)
            {
                if (ans % left == 0) break;
            }
            int right = ans / left;
            if (Random.Range(0, 2) < 1)
            {
                if (n > 2)
                    return left.ToString() + "*" + "(" + MakeString(right, n - 1) + ")";
                else return left.ToString() +"*"+ MakeString(right, n - 1);
            }
            else
            {
                if (n > 2)
                    return "(" + MakeString(left, n - 1) + ")" + "*" + right.ToString();
                else
                    return MakeString(left, n - 1) + "*" + right.ToString();
            }
        }
        else
        {
            int left;
            int right = Random.Range(2, 10);
            left = ans * right;
            if (Random.Range(0, 2) < 1)
            {
                if (n > 2)
                    return left.ToString() + "/" + "(" + MakeString(right, n - 1) + ")";
                else return left.ToString() +"/"+ MakeString(right, n - 1);
            }
            else
            {
                if(n>2)
                return "(" + MakeString(left, n - 1) + ")" + "/" + right.ToString();
                else
                    return MakeString(left, n - 1) + "/" + right.ToString();
            }
        }
 
    }
    void Update () {
        time -= Time.deltaTime;
        txtTime.GetComponent<Text>().text = "倒计时:" + ((int)time).ToString();
	}
}

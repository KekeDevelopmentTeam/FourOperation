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
    private void Awake()
    {
        instance = this;
    }
    void Start () {
		for(int i=0;i<count;i++)
        {
            int n = Random.Range(20, 1000);
            int m = Random.Range(2, 5);
            GameObject question = questionPrefab;
            question.transform.Find("Equation").GetComponent<Text>().text = MakeString(n, m);
            questions.Add(question);
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
                return left.ToString() +"*"+ "(" + MakeString(right, n - 1) + ")";
            }
            else
            {
                return "(" + MakeString(left, n - 1) + ")"+"*" + right.ToString();
            }
        }
        else
        {
            int left;
            int right = Random.Range(2, 10);
            left = ans * right;
            if (Random.Range(0, 2) < 1)
            {
                return left.ToString() + "/" + "(" + MakeString(right, n - 1) + ")";
            }
            else
            {
                return "(" + MakeString(left, n - 1) + ")" + "/" + right.ToString();
            }
        }
 
    }
    void Update () {
		
	}
}

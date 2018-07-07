using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Manager : MonoBehaviour {

    public GameObject questionPrefab;
    public Dictionary<int, int> qustions;
    public int count;
    public static Manager instance;
    private void Awake()
    {
        instance = this;
    }
    void Start () {
		for(int i=0;i<count;i++)
        {
            
        }
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
